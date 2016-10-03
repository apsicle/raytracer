#include <cmath>
#include <iostream>
#include "Vector.hpp"

/* Author: Ryan Yan
 * Date: 04/11/16
 * Section 1
 * 
 * Description: This is a raytracing program. This file defines several useful functions on vectors
 */

Vector::Vector (double x, double y, double z) {
  set(x, y, z);
}

Vector::Vector (void) {
  set(0, 0, 0);
}

void Vector::set (double x, double y, double z) {
  this -> x = x;
  this -> y = y;
  this -> z = z;
}

Vector Vector::add(Vector v){
  Vector rv;
  rv.x = x + v.x;
  rv.y = y + v.y;
  rv.z = z + v.z;
  return rv;
}

Vector Vector::operator + (Vector v) {
  return this -> add(v);
}

Vector Vector::subtract(Vector v){
  Vector rv;
  rv.x = x - v.x;
  rv.y = y - v.y;
  rv.z = z - v.z;
  return rv;
}

Vector Vector::operator - (Vector v){
  return this -> subtract(v);
}

Vector Vector::mult(Vector v){
  Vector rv;
  rv.x = x * v.x;
  rv.y = y * v.y;
  rv.z = z * v.z;
  return rv;
}

Vector Vector::operator * (Vector v) {
  return this -> mult(v);
}

Vector Vector::scalar_mult(double d) {
  Vector rv;
  rv.x = d * x;
  rv.y = d * y;
  rv.z = d * z;
  return rv;
}

Vector Vector::operator * (double d) {
  return this -> scalar_mult(d);
}

Vector Vector::scalar_divide(double d) {
  Vector rv;
  rv.x = x / d;
  rv.y = y / d;
  rv.z = z / d;
  return rv;
}

Vector Vector::operator / (double d) {
  return this -> scalar_divide(d);
}

double Vector::sum_components (void) {
  return x + y + z;
}

double Vector::length (void) {
  return std::sqrt(x*x + y*y + z*z);
}

void Vector::normalize (void) {
    //Normalizing the vector normalizes each component such that the length of the vector is 1.
  double magnitude = length();  
  this -> x = x / magnitude;
  this -> y = y / magnitude;
  this -> z = z / magnitude;
}

double Vector::dot (Vector v) {
    //Sum of elementwise products of two vectors.
    double sum = mult(v).sum_components();
    return sum;
}

void Vector::print (void) {
  std::cout << "x: " << this -> x << "\ny: " << this -> y << "\nz: " << this -> z << "\n"; 
}

/*
int main() {
  Vector test;
  Vector test1;
  Vector test2;
  test.print();
  
  test2 = test.add(Vector (2,3,4));
  test2.print();
  test1.set(1,1,1);
  std::cout << test1.dot(test2);
  test2.print();
  std::cout << test2.length();
  test2.normalize();
  test2.print();
  (test1 / 4).print();
  (test1 * 2).print();
  return 0;
}*/