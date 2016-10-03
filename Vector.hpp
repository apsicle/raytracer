#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/* Author: Ryan Yan
 * Date: 04/11/16
 * Section 1
 * 
 * Description: This is a raytracing program. This header file defines the vector structure
 */

class Vector {
//Magnitude and direction.
private:
  double x;
  double y;
  double z;
public:
  Vector(void);
  Vector(double x, double y, double z);
  void set(double x, double y, double z);
  Vector add(Vector);
  Vector operator+(Vector);
  Vector subtract(Vector);
  Vector operator-(Vector);
  Vector mult(Vector);
  Vector operator*(Vector);
  Vector scalar_mult(double);
  Vector operator*(double);
  Vector scalar_divide(double);
  Vector operator/(double);
  double sum_components(void);
  double length(void);
  double dot (Vector);
  void normalize (void);
  void print(void);
};



#endif