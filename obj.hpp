#ifndef OBJ_HPP_
#define OBJ_HPP_
#include "rt.hpp"
#include "Sphere.hpp"

typedef struct OBJ {
    //The node class
    Sphere sphere;
    COLOR_T color;
    struct OBJ *next;
} OBJ_T; 

#endif