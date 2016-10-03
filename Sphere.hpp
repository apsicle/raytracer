#ifndef SPHERE_HPP_
#define SPHERE_HPP_
#include "rt.hpp"
#include "Vector.hpp"

class Sphere {
//It's a sphere.
private:
  Vector ctr;
  double radius;
public:
  void set (Vector, double);
  bool intersect (RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};


#endif