//
//  math3.h
//  
//
//  Created by Matthew Baptist on 5/23/16.
//
//

#ifndef math3_h
#define math3_h

#include <stdio.h>

/* Compute the dot product of the vectors */
float dot(int dim, float[] vec1, float[] vec2);

/* Computer the vector sum */
void add(int dim, float[] vec1, float[] vec2, float[] rslt);

/* Compute the vector diff */
void sub(int dim, float[] vec1, float[] vec2, float[] rslt);

/* Find the unit vector in the direction of vec */
void norm(int dim, float[] vec, float[] rslt);

/* Scale vec by scalar */
void scale(int dim, float[] vec, float scalar, float[] rslt);

#endif /* math3_h */
