#include <iostream>
#include <cstdio>
#include <cmath>
#include "rt.hpp"
#include "obj.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"

/* Author: Ryan Yan
 * Date: 04/24/16
 * Section 1
 * 
 * Description: This is a raytracing program. This produces a 2-d graphical depiction of
 * spheres based on information in a formatted text file from the vantage point of a viewer behind a canvas.
 * This works with both sphere.txt and spheres.txt.
 */

void read_objs (OBJ_T** list) {
    //This function takes a declared linked list, and reads in stdinput (redirected from console) of spheres or sphere.txt
    
    //Declare vars
    double x, y, z;
    double radius;
    Sphere input_sphere;
    COLOR_T color; 
    
    //Scan in series of 7 floats (formatted in spheres.txt)
    while(std::cin >> x >> y >> z >> radius >> color.R >> color.G >> color.B != NULL) {
	OBJ_T * node = new OBJ_T;       	//allocate memory for new node object.
	input_sphere.set(Vector(x, y, z), radius);
	node->sphere = input_sphere;
	node->color = color;
	node->next = *list;				//add node to head of linked list and change head pointer.
	*list = node;
    }
}

COLOR_T Trace (RAY_T ray, OBJ_T* list, Light light) {
    //Iterates through the linked list of spheres and finds the color associated with the sphere closest to the viewer
    
    //Declare vars
    OBJ_T* mylist = list;
    double min_t;
    double t;
    t = min_t = 1000;
    OBJ_T* closest_obj = NULL;
    OBJ_T* curr_obj = NULL;
    Vector closest_int_pt;
    Vector curr_int_pt;
    Vector closest_normal;
    Vector curr_normal;
    COLOR_T color = {0,0,0}; //If we find no intersections, default to black!
    
    for(curr_obj = list; curr_obj != NULL; curr_obj = curr_obj -> next){
      if (curr_obj->sphere.intersect(ray, t, curr_int_pt, curr_normal)) {
	if (t < min_t) {
	  closest_obj = curr_obj;
	  closest_int_pt = curr_int_pt;
	  closest_normal = curr_normal;
	  min_t = t;
	}
      }
      mylist = mylist -> next;
    }
    if(closest_obj != NULL){
      color = light.illuminate(ray, closest_obj -> color, closest_int_pt, closest_normal);
    }
    return color;
	  
  //printf("%lf %lf %lf %lf %lf %lf %lf", mylist -> sphere.center.x, mylist -> sphere.center.y, mylist -> sphere.center.z, 
	//  mylist -> sphere.radius, mylist -> color.R, mylist -> color.G, mylist -> color.B);
  
}

int main() {
  //Set vars
  int maxy = 1000, maxx = 1000;
  double y, x;
  Vector origin(0,0,0);
  double t;
  COLOR_T pixel;
  Light light;
  light.set(5, 10, 0);
  
  //Write ppm header.
  std::cout << "P6\n" << maxx << "\n" << maxy << "\n255\n";
  
  //Create a linked list, setting sentinel node.
  OBJ_T* mylist = new OBJ_T;
  mylist -> next = NULL;
  read_objs (&mylist);
  
  //Write image data by looping through pixels and checking intersections with all spheres
  for (y = maxy; y > 0; y--) {
      for (x = 0; x < maxx; x++) {
	  //Set ray
	  Vector dir(-0.5 + (x / 1000), -0.5 + (y / 1000), 1);
	  dir.normalize();
	  RAY_T ray = {origin, dir};
	  
	  //Set pixel color with cast and multiply by 255. We use a number from 0 to 1 multiplied by 255 for extra precision.
	  pixel = Trace(ray, mylist, light);
	  if(pixel.R > 1.0) {
	    pixel.R = 1.0;
	  }
	  if(pixel.G > 1.0) {
	    pixel.G = 1.0; 
	  }
	  if(pixel.B > 1.0) {
	    pixel.B = 1.0;
	  }
	  pixel.R = pixel.R * 255;
	  pixel.G = pixel.G * 255;
	  pixel.B = pixel.B * 255;
	  
	  //Print out pixels as characters to the ppm.
	  std::cout << (unsigned char) pixel.R << (unsigned char) pixel.G << (unsigned char) pixel.B;
      }
  }
  
  //delete the dynamically allocated memory by iterating through the linked list
  OBJ_T* curr;
  while (mylist != NULL) {
	curr = mylist;
	mylist = mylist -> next;
	delete(curr);
  }
  
  //Always return 0, kids.
  return 0;
}
  