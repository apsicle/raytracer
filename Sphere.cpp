#include "Sphere.hpp"
#include "rt.hpp"
#include <iostream>
#include <cmath>


void Sphere::set (Vector ctr, double radius) {
  this -> ctr = ctr;
  this -> radius = radius;
}

bool Sphere::intersect (RAY_T ray, double &t, Vector &int_pt, Vector &normal) {
    //Passed in a ray, a sphere, and the previously held minimum distance t.
    //Returns 1 when found intersection and 0 when not. Sets t to minimum of the roots (intersections) when found.
    
    //Declare vars
    Vector origin = ray.origin;
    Vector dir = ray.dir;
    
    //printf("s.c.x: %lf s.c.y: %lf s.c.z: %lf dirx: %lf diry: %lf dirz: %lf\n", center.x, center.y, center.z,
    //dir.x, dir.y, dir.z);
    
    //Analytical solution to the intersection of a ray and a sphere in 3 dimensions. We can write a parametric equation
    //of the normalized Vector representing the ray, and solve a quadratic equation for the distance t between the origin
    //of the ray and the intersection.
    
    double A = 1;
    double B = dir.dot(origin - ctr) * 2;
    double C = (origin - ctr).dot(origin - ctr) - radius*radius;
   
    double discriminant = B*B - 4*A*C;
    
    //printf("A: %lf B: %lf C: %lf Disc: %lf\n", A, B, C, discriminant);
    
    if(discriminant <= 0) {
	//no real roots, so exit w/o finding intersection.
	return 0;
    }
    else {
	double root1 = (-B + std::sqrt(discriminant)) / 2;
	double root2 = (-B - std::sqrt(discriminant)) / 2;
	
	if (root1 <= 0 && root2 <= 0) {
	    return 0; //both negative roots means we're in front of the image, so we can't see it.
	}
	else if (root1 <= root2) {
	    //We return the smaller root (minimum distance)
	    t = root1;
	    int_pt = origin + (dir * t);
	    normal = (int_pt - ctr) / radius;
	    return 1;
	}
	else {
	    t = root2;
	    int_pt = origin + (dir * t);
	    normal = (int_pt - ctr) / radius;
	    return 1;
	}
    }
    
}