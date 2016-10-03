#ifndef LIGHT_HPP_
#define LIGHT_HPP_
#include "Vector.hpp"
#include "rt.hpp"

class Light {
private:
  Vector loc;
public:
  Light(void);
  Light(double, double, double);
  void set(double, double, double);
  COLOR_T illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal);
};

#endif