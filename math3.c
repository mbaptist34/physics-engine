//
//  math3.c
//  
//
//  Created by Matthew Baptist on 5/23/16.
//
//

#include "math3.h"

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