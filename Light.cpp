#include "Light.hpp"
#include <cmath>

void Light::set (double x, double y, double z) {
  this -> loc.set(x, y, z);
}

Light::Light(void) {
  set(5, 10, 0);
}


Light::Light(double x, double y, double z) {
  set(x, y, z);
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal) {
  COLOR_T col;
  
  //Ambient
  col.R = surface_col.R * 0.1;
  col.G = surface_col.G * 0.1;
  col.B = surface_col.B * 0.1;
  
  //Diffuse
  Vector L;
  L = loc - int_pt;
  L.normalize();
  double dotted = L.dot(normal);
  if(dotted > 0) {
    col.R += dotted * surface_col.R;
    col.G += dotted * surface_col.G;
    col.B += dotted * surface_col.B;
    
    //Specular
    Vector R = L - (normal * (normal.dot(L)) * 2);
    R.normalize();
    double dot2 = R.dot(ray.dir);
    if(dot2 > 0) {
      col.R += pow(dot2, 200);
      col.G += pow(dot2, 200);
      col.B += pow(dot2, 200);
    }
  }  
  return col;
}
  