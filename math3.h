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

/*
    Vector Operations:
    -dot
    -add
    -sub
    -norm
    -scale
 */

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

/*
  Note: These ops are only defined on square matrices.
  Matrix Operations:
  -add
  -sub
  -mul
  -det
  -inv
 */

/* Component wise addition of the two matrices, stored in rslt */
void add(int dim, float[] mat1, float[] mat2, float[] rslt);

/* Component wise subtraction of the two matrices, stored in rslt */
void sub(int dim, float[] mat1, float[] mat2, float[] rslt);

/* Compute the matrix multiplication of the two matrices, store in rslt */
void mul(int dim, float[] mat1, float[] mat2, float[] rslt);

/* Compute the determinant of the matrix */
float det(int dim, float[] mat);

/* Find the inverse of the square matrix if one exists */
void inv(int dim, float[] mat, float[] rslt);

/* Matrix multiplication for two sq
#endif /* math3_h */
