//
//  math3.hpp
//  
//
//  Created by Matthew Baptist on 4/10/17.
//
//

#ifndef math3_hpp
#define math3_hpp

#include <stdio.h>
#include <iostream>

class vec3{
  float values[3];
  
  public:
  
  vec3(float x, float y, float z);
  vec3();
  vec3(float values[3]);
  std::string to_string();
  
  vec3 copy();
  float magnitude();
  vec3& normalize();
  
  const float& operator[] (int index) const;
  float& operator[] (int index);
  
  vec3 operator+(const vec3& b);
  vec3 operator-(const vec3& b);
  
};

class vec4{
  float values[4];
  
  public:
  
  vec4(float x, float y, float z, float w);
  vec4();
  vec4(float values[4]);
  std::string to_string();
  
  vec4 copy();
  float magnitude();
  vec4& normalize();
  
  const float& operator[] (int index) const;
  float& operator[] (int index);
  
  vec4 operator+(const vec4& b);
  vec4 operator-(const vec4& b);
  
};

vec3 scale(const vec3& a, const float scalar); //Gives the vector a scaled by scalar
float dot(const vec3& a, const vec3& b); //Gives the dot product of a and b
vec3 max(const vec3& a, const vec3& b); //Gives the vector w/ the maximal elements of a and b
vec3 min(const vec3& a, const vec3& b); //Gives the vector w/ the minimal elements of a and b
bool cmp(const vec3& a, const vec3& b); //Compares the two vectors for testing purposes
vec3 lerp(const vec3& a, const vec3& b, float t); //interpolates between a and b for 0 <= t <= 1


vec4 scale(const vec4& a, const float scalar); //Gives the vector a scaled by scalar
float dot(const vec4& a, const vec4& b); //Gives the dot product of a and b
vec4 max(const vec4& a, const vec4& b); //Gives the vector w/ the maximal elements of a and b
vec4 min(const vec4& a, const vec4& b); //Gives the vector w/ the minimal elements of a and b
bool cmp(const vec4& a, const vec4& b); //Compares the two vectors for testing purposes
vec4 lerp(const vec4& a, const vec4& b, float t); //interpolates between a and b for 0 <= t <= 1


//Column Major 4x4 Matrix
class mat4 {
  
  vec4 columns[4];
  
  public:
  
  mat4();
  mat4(const vec4& x, const vec4& y, const vec4& z, const vec4& w);

  std::string to_string();
  mat4 copy();
  
  const vec4& operator[](int index) const;
  vec4& operator[](int index);
  
};

vec4 operator*(const mat4& m, const vec4& v); //right multiplication
vec4 operator*(const vec4& v, const mat4& m); //left multiplication
mat4 operator*(const mat4& m, const mat4& v); //mat4 x mat4 multiplication




#endif /* math3_hpp */
