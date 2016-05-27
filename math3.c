//
//  math3.c
//  
//
//  Created by Matthew Baptist on 5/23/16.
//
//

#include "math3.h"

/* Vector Operations */

float dot(int dim, float[] vec1, float[] vec2){
  
  float accum = 0;
  
  for(int i=0; i < dim; i++){
    accum += vec1[i] * vec2[i];
  }
  
  return accum;
}

void add(int dim, float[] vec1, float[] vec2, float[] rslt){
  
  /* Component wise addition */
  for(int i=0; i < dim; i++){
    rslt[i] = vec1[i] + vec2[i];
  }
}

void sub(int dim, float[] vec1, float[] vec2, float[] rslt){
  
  /* Component wise subtraction */
  for(int i=0; i < dim; i++){
    rslt[i] = vec1[i] - vec2[i];
  }
}

void norm(int dim, float[] vec, float[] rslt){
  
  float mag = dot(vec, vec);
  
  scale(vec, 1/mag, rslt);
  
}

void scale(int dim, float[] vec, float scalar, float[] rslt) {
  
  for(int i=0; i < dim; i++){
    rslt[i] = vec[i] * scalar;
  }
}

/* Matrix Operations */


/* Component wise addition of the two matrices, stored in rslt */
void add(int dim, float[] mat1, float[] mat2, float[] rslt) {
  
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      rslt[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
}

/* Component wise subtraction of the two matrices, stored in rslt */
void sub(int dim, float[] mat1, float[] mat2, float[] rslt) {
  
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      rslt[i][j] = mat1[i][j] - mat2[i][j];
    }
  }
}

/* Compute the matrix multiplication of the two matrices, store in rslt */
void mul(int dim, float[] mat1, float[] mat2, float[] rslt) {
  
  float entry = 0;
  for(int i = 0; i < dim; i++){
    for(int j = 0; j < dim; j++){
      entry = 0
      for(int k = 0; k < dim; k++){
        entry += mat1[i][k] * mat2[k][j]
      }
      rslt[i][j] = entry;
    }
  }
}

/* Compute the determinant of the matrix */
float det(int dim, float[] mat);

/* Find the inverse of the square matrix if one exists */
void inv(int dim, float[] mat, float[] rslt);


