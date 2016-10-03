#ifndef RT_HPP_
#define RT_HPP_
#include "Vector.hpp"

/* Author: Ryan Yan
 * Date: 04/24/16
 * Section 1
 * 
 * Description: This is a raytracing program. This header file defines several useful structures
 */

typedef struct RAY {
    //An infinite length Vector
    Vector origin;
    Vector dir;
} RAY_T;

typedef struct COLOR {
    //For pixel shading
    double R;
    double G;
    double B;
} COLOR_T;



#endif

