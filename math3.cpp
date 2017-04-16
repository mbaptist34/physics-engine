//
//  math3.cpp
//  
//
//  Created by Matthew Baptist on 4/10/17.
//
//

#include "math3.hpp"
#include <algorithm>
#include <cmath>
#include <assert.h>
#include "AlmostEquals.h"

vec3::vec3(float x, float y, float z){
  
  values[0] = x;
  values[1] = y;
  values[2] = z;
  
}

vec3::vec3(){
  
  values[0] = 0;
  values[1] = 0;
  values[2] = 0;
  
}

vec3::vec3(float values[3]){
  
  std::copy(values, values + 3, this->values);
  
}

std::string vec3::to_string(){
  
  return std::to_string(values[0]) + " " +
    std::to_string(values[1]) + " " +
    std::to_string(values[2]);
  
}
  
vec3 vec3::copy(){
  
    return vec3(values);
  
}

float vec3::magnitude(){
  
  float temp = dot(*this, *this);
  temp = std::sqrt(temp);
  return temp;
  
}

vec3& vec3::normalize(){
  
  float temp = this->magnitude();
  for (int i = 0; i < 3; i++){
    values[i] /= temp;
  }
  return *this;
  
}

const float& vec3::operator[] (int index) const{
  
  return values[index];
  
}

float& vec3::operator[] (int index){
  
  return values[index];
  
}
  
vec3 vec3::operator+(const vec3& b){
  
  vec3 sum((*this)[0] + b[0],
           (*this)[1] + b[1],
           (*this)[2] + b[2]);
  
  return sum;
  
}
vec3 vec3::operator-(const vec3& b){
  
  vec3 dif((*this)[0] - b[0],
           (*this)[1] - b[1],
           (*this)[2] - b[2]);
  
  return dif;
  
}

vec3 scale(const vec3& a, const float scalar) { //Gives the vector a scaled by scalar
  
  vec3 b(a[0] * scalar,
         a[1] * scalar,
         a[2] * scalar);
  
  return b;
  
}

float dot(const vec3& a, const vec3& b) { //Gives the dot product of a and b
  
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  
}

vec3 max(const vec3& a, const vec3& b) { //Gives the vector w/ the maximal elements of a and b

  vec3 temp( std::max(a[0],b[0]), std::max(a[1],b[1]), std::max(a[2],b[2]));
  
  return temp;

}
vec3 min(const vec3& a, const vec3& b) { //Gives the vector w/ the minimal elements of a and b

  vec3 temp( std::min(a[0],b[0]), std::min(a[1],b[1]), std::min(a[2],b[2]) );

  return temp;

}

bool cmp(const vec3& a, const vec3& b) { //Compares the two vectors for testing purposes

  bool val = true;
  
  
  val = val & (AlmostEquals(a[0], b[0])); //Using the ULP comparison from google test
  val = val & (AlmostEquals(a[1], b[1]));
  val = val & (AlmostEquals(a[2], b[2]));
  
  return val;

}

//interpolates between a and b for 0 <= t <= 1
vec3 lerp(const vec3& a, const vec3& b, const float t) {
  
  assert(0 <= t);
  assert(t <= 1);
  
  vec3 interp( (1 - t) * a[0] + t * b[0],
               (1 - t) * a[1] + t * b[1],
               (1 - t) * a[2] + t * b[2] );
  
  return interp;

}

vec4::vec4(float x, float y, float z, float w){
  
  values[0] = x;
  values[1] = y;
  values[2] = z;
  values[3] = w;
  
}

vec4::vec4(){
  
  values[0] = 0;
  values[1] = 0;
  values[2] = 0;
  values[3] = 0;
  
}

vec4::vec4(float values[4]){
  
  std::copy(values, values + 4, this->values);
  
}

std::string vec4::to_string(){
  
  return std::to_string(values[0]) + " " +
  std::to_string(values[1]) + " " +
  std::to_string(values[2]) + " " +
  std::to_string(values[3]);
  
}

vec4 vec4::copy(){
  
  return vec4(values);
  
}

float vec4::magnitude(){
  
  float temp = dot(*this, *this);
  temp = std::sqrt(temp);
  return temp;
  
}

vec4& vec4::normalize(){
  
  float temp = this->magnitude();
  for (int i = 0; i < 4; i++){
    values[i] /= temp;
  }
  return *this;
  
}

const float& vec4::operator[] (int index) const{
  
  return values[index];
  
}

float& vec4::operator[] (int index){
  
  return values[index];
  
}

vec4 vec4::operator+(const vec4& b){
  
  vec4 sum((*this)[0] + b[0],
           (*this)[1] + b[1],
           (*this)[2] + b[2],
           (*this)[3] + b[3]);
  
  return sum;
  
}
vec4 vec4::operator-(const vec4& b){
  
  vec4 dif((*this)[0] - b[0],
           (*this)[1] - b[1],
           (*this)[2] - b[2],
           (*this)[3] - b[3]);
  
  return dif;
  
}

vec4 scale(const vec4& a, const float scalar) { //Gives the vector a scaled by scalar
  
  vec4 b(a[0] * scalar,
         a[1] * scalar,
         a[2] * scalar,
         a[3] * scalar);
  
  return b;
  
}

float dot(const vec4& a, const vec4& b) { //Gives the dot product of a and b
  
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
  
}

vec4 max(const vec4& a, const vec4& b) { //Gives the vector w/ the maximal elements of a and b
  
  vec4 temp( std::max(a[0],b[0]), std::max(a[1],b[1]), std::max(a[2],b[2]), std::max(a[3],b[3]) );
  
  return temp;
  
}
vec4 min(const vec4& a, const vec4& b) { //Gives the vector w/ the minimal elements of a and b
  
  vec4 temp( std::min(a[0],b[0]), std::min(a[1],b[1]), std::min(a[2],b[2]), std::min(a[3],b[3]) );
  
  return temp;
  
}

bool cmp(const vec4& a, const vec4& b) { //Compares the two vectors for testing purposes
  
  bool val = true;
  
  
  val = val & (AlmostEquals(a[0], b[0])); //using the ULP comparison from google test
  val = val & (AlmostEquals(a[1], b[1]));
  val = val & (AlmostEquals(a[2], b[2]));
  val = val & (AlmostEquals(a[3], b[3]));
  
  return val;
  
}

//interpolates between a and b for 0 <= t <= 1
vec4 lerp(const vec4& a, const vec4& b, const float t) {
  
  assert(0 <= t);
  assert(t <= 1);
  
  vec4 interp( (1 - t) * a[0] + t * b[0],
              (1 - t) * a[1] + t * b[1],
              (1 - t) * a[2] + t * b[2],
              (1 - t) * a[3] + t * b[3]);
  
  return interp;
  
}

//Column Major 4x4 Matrix

mat4::mat4() { //Initialize to identity
  
  (*this)[0] = vec4(1, 0, 0, 0);
  (*this)[1] = vec4(0, 1, 0, 0);
  (*this)[2] = vec4(0, 0, 1, 0);
  (*this)[3] = vec4(0, 0, 0, 1);
  
}

mat4::mat4(const vec4& x, const vec4& y, const vec4& z, const vec4& w) {
  
  (*this)[0] = x;
  (*this)[1] = y;
  (*this)[2] = z;
  (*this)[3] = w;
  
}
  
std::string mat4::to_string(){

  return (*this)[0].to_string() + ";\n" +
         (*this)[1].to_string() + ";\n" +
         (*this)[2].to_string() + ";\n" +
         (*this)[3].to_string();
  
}

mat4 mat4::copy() {
  
  return mat4( (*this)[0].copy(),
               (*this)[1].copy(),
               (*this)[2].copy(),
               (*this)[3].copy() );
  
}

const vec4& mat4::operator[](int index) const {
  
  return columns[index];
  
}
vec4& mat4::operator[](int index) {
  
  return columns[index];
  
}

vec4 operator*(const mat4& m, const vec4& v) { //right multiplication
 
  return vec4(
              m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
              m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
              m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
              m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3]);
  
}

vec4 operator*(const vec4& v, const mat4& m) { //left multiplication
  
  return vec4(
              dot(v, m[0]),
              dot(v, m[1]),
              dot(v, m[2]),
              dot(v, m[3]));
  
}

mat4 operator*(const mat4& m1, const mat4& m2) { //mat4 x mat4 multiplication

  vec4 x = m1 * m2[0];
  vec4 y = m1 * m2[1];
  vec4 z = m1 * m2[2];
  vec4 w = m1 * m2[3];
  
  return mat4(x, y, z, w);

}
