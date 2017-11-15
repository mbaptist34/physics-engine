//
//  math3test.cpp
//  
//
//  Created by Matthew Baptist on 4/11/17.
//
//

#include "gtest/gtest.h"
#include "math3.hpp"

TEST(vec3test, constructorNoArgs) {
  
  vec3 a;
  
  EXPECT_EQ(a[0], 0);
  EXPECT_EQ(a[1], 0);
  EXPECT_EQ(a[2], 0);
  
}

TEST(vec3test, constructor3floats) {
  
  vec3 a(1.0, 1.0, 1.0);
  
  EXPECT_EQ(a[0], 1.0);
  EXPECT_EQ(a[1], 1.0);
  EXPECT_EQ(a[2], 1.0);
  
}

TEST(vec3test, constructorArray) {
  
  float temp[] = {1.0, 1.0, 1.0};
  
  EXPECT_EQ(temp[0], 1.0);
  EXPECT_EQ(temp[1], 1.0);
  EXPECT_EQ(temp[2], 1.0);
  
  vec3 a(temp);
  
  EXPECT_EQ(a[0], 1.0);
  EXPECT_EQ(a[1], 1.0);
  EXPECT_EQ(a[2], 1.0);
  
}

TEST(vec3test, to_stringTest) {
  
  vec3 a(1.0, 1.0, 1.0);
  
  EXPECT_EQ(a.to_string(), "1.000000 1.000000 1.000000");
  
}

TEST(vec3test, copyTest) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b = a.copy();
  
  EXPECT_EQ(a[0], b[0]);
  EXPECT_EQ(a[1], b[1]);
  EXPECT_EQ(a[2], b[2]);
  
  a[0] = 2.0;
  a[1] = 2.0;
  a[2] = 2.0;
  
  EXPECT_EQ(a[0], 2.0);
  EXPECT_EQ(a[1], 2.0);
  EXPECT_EQ(a[2], 2.0);
  
  EXPECT_EQ(b[0], 1.0);
  EXPECT_EQ(b[1], 1.0);
  EXPECT_EQ(b[2], 1.0);
  
}

TEST(vec3test, dotTestReflexive) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b(2.0, 2.0, 2.0);
  
  float three = dot(a, a);
  float twelve = dot(b, b);
  
  EXPECT_EQ(three, 3.0);
  EXPECT_EQ(twelve, 12.0);
  
}

TEST(vec3test, dotTestMultiple) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b(2.0, 2.0, 2.0);
  
  float six = dot(a, b);
  
  EXPECT_EQ(six, 6.0);
  
}

TEST(vec3test, dotTestSymmetric) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b(2.0, 2.0, 2.0);
  
  float six = dot(a, b);
  float othersix = dot(b, a);
  
  EXPECT_EQ(six, othersix);
  
}

TEST(vec3test, magnitudeTest) {
  
  vec3 a(2.0, 2.0, 1.0);
  
  float three = a.magnitude();
  
  EXPECT_EQ(three, 3.0);
  
}

TEST(vec3test, normalizeTest) {
  
  vec3 a(2.0, 2.0, 1.0);
  
  vec3 b = a.copy().normalize().copy();
  
  EXPECT_FLOAT_EQ(b[0], 2.0/3.0);
  EXPECT_FLOAT_EQ(b[1], 2.0/3.0);
  EXPECT_FLOAT_EQ(b[2], 1.0/3.0);
  
}

TEST(vec3test, addTest) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b(2.0, 2.0, 2.0);
  vec3 c = a + b;
  
  EXPECT_FLOAT_EQ(c[0], 3.0);
  EXPECT_FLOAT_EQ(c[1], 3.0);
  EXPECT_FLOAT_EQ(c[2], 3.0);
  
}

TEST(vec3test, subTest) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b(2.0, 2.0, 2.0);
  vec3 c = b - a;
  
  EXPECT_FLOAT_EQ(c[0], 1.0);
  EXPECT_FLOAT_EQ(c[1], 1.0);
  EXPECT_FLOAT_EQ(c[2], 1.0);
  
}

TEST(vec3test, scaleTest) {
  
  vec3 a(1.0, 2.0, 3.0);
  
  vec3 b = scale(a, 3.0);
  
  EXPECT_FLOAT_EQ(b[0], 3.0);
  EXPECT_FLOAT_EQ(b[1], 6.0);
  EXPECT_FLOAT_EQ(b[2], 9.0);
  
}

TEST(vec3test, maxTest) {
  
  vec3 a(10.0, 2.0, 15.0);
  vec3 b(5.0, 5.0, 5.0);
  vec3 c(15.0, 1.0, 20.0);
  
  vec3 d = max(a, b);
  vec3 e = max(a, c);
  
  EXPECT_FLOAT_EQ(d[0], 10.0);
  EXPECT_FLOAT_EQ(d[1], 5.0);
  EXPECT_FLOAT_EQ(d[2], 15.0);
  
  EXPECT_FLOAT_EQ(e[0], 15.0);
  EXPECT_FLOAT_EQ(e[1], 2.0);
  EXPECT_FLOAT_EQ(e[2], 20.0);
  
}

TEST(vec3test, minTest) {
  
  vec3 a(10.0, 2.0, 15.0);
  vec3 b(5.0, 5.0, 5.0);
  vec3 c(15.0, 1.0, 20.0);
  
  vec3 d = min(a, b);
  vec3 e = min(a, c);
  
  EXPECT_FLOAT_EQ(d[0], 5.0);
  EXPECT_FLOAT_EQ(d[1], 2.0);
  EXPECT_FLOAT_EQ(d[2], 5.0);
  
  EXPECT_FLOAT_EQ(e[0], 10.0);
  EXPECT_FLOAT_EQ(e[1], 1.0);
  EXPECT_FLOAT_EQ(e[2], 15.0);
  
}

TEST(vec3test, cmpTest) {
  
  vec3 a(10.0, 2.0, 15.0);
  vec3 b(5.0 + 5.0, 1.0 + 1.0, 7.5 + 7.5);
  
  vec3 c(1000000.0, 500000.0, 1500000.0);
  vec3 d(100000.0 * 10.0, 50000.0 * 10.0, 150000.0 * 10.0);
  
  
  EXPECT_TRUE(cmp(a,a));
  EXPECT_TRUE(cmp(a,b));
  EXPECT_TRUE(cmp(b,a));
  EXPECT_TRUE(cmp(b,b));
  
  EXPECT_TRUE(cmp(c,c));
  EXPECT_TRUE(cmp(d,d));
  EXPECT_TRUE(cmp(c,d));
  EXPECT_TRUE(cmp(d,c));
  
}

TEST(vec3test, cmpNearZeroTest) {
  
  vec3 a(2.0, 2.0, 2.0);
  vec3 b(1.0, 1.0, 1.0);
  
  vec3 c = a - b;
  c = c - b;
  
  vec3 d; //Zero Constructor
  
  EXPECT_TRUE(cmp(c,d));
  
}

TEST(vec3test, lerpTest) {
  
  vec3 a(1.0, 1.0, 1.0);
  vec3 b(2.0, 3.0, 4.0);
  vec3 c(1.5, 2.0, 2.5);
  
  vec3 d;
  d = lerp(a, b, 0.0);
  EXPECT_TRUE(cmp(a,d));
  
  d = lerp(a, b, 1.0);
  EXPECT_TRUE(cmp(b, d));
  
  d = lerp(a, b, 0.5);
  EXPECT_TRUE(cmp(c, d));
  
}

/* vec4 tests begin below */

TEST(vec4test, constructorNoArgs) {
  
  vec4 a;
  
  EXPECT_EQ(a[0], 0);
  EXPECT_EQ(a[1], 0);
  EXPECT_EQ(a[2], 0);
  EXPECT_EQ(a[3], 0);
  
}

TEST(vec4test, constructor4floats) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  
  EXPECT_EQ(a[0], 1.0);
  EXPECT_EQ(a[1], 1.0);
  EXPECT_EQ(a[2], 1.0);
  EXPECT_EQ(a[3], 1.0);
  
}

TEST(vec4test, constructorArray) {
  
  float temp[] = {1.0, 1.0, 1.0, 1.0};
  
  EXPECT_EQ(temp[0], 1.0);
  EXPECT_EQ(temp[1], 1.0);
  EXPECT_EQ(temp[2], 1.0);
  EXPECT_EQ(temp[3], 1.0);
  
  vec4 a(temp);
  
  EXPECT_EQ(a[0], 1.0);
  EXPECT_EQ(a[1], 1.0);
  EXPECT_EQ(a[2], 1.0);
  EXPECT_EQ(a[3], 1.0);
  
}

TEST(vec4test, to_stringTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  
  EXPECT_EQ(a.to_string(), "1.000000 1.000000 1.000000 1.000000");
  
}

TEST(vec4test, copyTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b = a.copy();
  
  EXPECT_EQ(a[0], b[0]);
  EXPECT_EQ(a[1], b[1]);
  EXPECT_EQ(a[2], b[2]);
  EXPECT_EQ(a[3], b[3]);
  
  a[0] = 2.0;
  a[1] = 2.0;
  a[2] = 2.0;
  a[3] = 2.0;
  
  EXPECT_EQ(a[0], 2.0);
  EXPECT_EQ(a[1], 2.0);
  EXPECT_EQ(a[2], 2.0);
  EXPECT_EQ(a[3], 2.0);

  
  EXPECT_EQ(b[0], 1.0);
  EXPECT_EQ(b[1], 1.0);
  EXPECT_EQ(b[2], 1.0);
  EXPECT_EQ(b[3], 1.0);
  
}

TEST(vec4test, dotTestReflexive) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(2.0, 2.0, 2.0, 2.0);
  
  float four = dot(a, a);
  float sixteen = dot(b, b);
  
  EXPECT_EQ(four, 4.0);
  EXPECT_EQ(sixteen, 16.0);
  
}

TEST(vec4test, dotTestMultiple) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(2.0, 2.0, 2.0, 2.0);
  
  float eight = dot(a, b);
  
  EXPECT_EQ(eight, 8.0);
  
}

TEST(vec4test, dotTestSymmetric) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(2.0, 2.0, 2.0, 2.0);
  
  float eight = dot(a, b);
  float othereight = dot(b, a);
  
  EXPECT_EQ(eight, 8.0);
  EXPECT_EQ(othereight, 8.0);
  
}

TEST(vec4test, magnitudeTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(2.0, 2.0, 2.0, 2.0);
  
  float two = a.magnitude();
  float four = b.magnitude();
  
  EXPECT_EQ(two, 2.0);
  EXPECT_EQ(four, 4.0);
  
}

TEST(vec4test, normalizeTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(2.0, 2.0, 2.0, 2.0);
  
  vec4 c = a.copy().normalize().copy();
  vec4 d = b.copy().normalize().copy();

  
  EXPECT_FLOAT_EQ(c[0], 1.0/2.0);
  EXPECT_FLOAT_EQ(c[1], 1.0/2.0);
  EXPECT_FLOAT_EQ(c[2], 1.0/2.0);
  EXPECT_FLOAT_EQ(c[3], 1.0/2.0);
  
  EXPECT_FLOAT_EQ(d[0], 2.0/4.0);
  EXPECT_FLOAT_EQ(d[1], 2.0/4.0);
  EXPECT_FLOAT_EQ(d[2], 2.0/4.0);
  EXPECT_FLOAT_EQ(d[3], 2.0/4.0);

  
}

TEST(vec4test, normalizeZeroTest) {
  
  vec4 a(1.0, 2.0, 2.0, 0);
  
  vec4 b = a.copy().normalize().copy();
  
  EXPECT_FLOAT_EQ(b[0], 1.0/3.0);
  EXPECT_FLOAT_EQ(b[1], 2.0/3.0);
  EXPECT_FLOAT_EQ(b[2], 2.0/3.0);
  EXPECT_FLOAT_EQ(b[3], 0);
  
}

TEST(vec4test, addTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(1.0, 2.0, 3.0, 4.0);
  vec4 c = a + b;
  
  EXPECT_FLOAT_EQ(c[0], 2.0);
  EXPECT_FLOAT_EQ(c[1], 3.0);
  EXPECT_FLOAT_EQ(c[2], 4.0);
  EXPECT_FLOAT_EQ(c[3], 5.0);

  
}

TEST(vec4test, subTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(1.0, 2.0, 3.0, 4.0);
  vec4 c = b - a;
  
  EXPECT_FLOAT_EQ(c[0], 0);
  EXPECT_FLOAT_EQ(c[1], 1.0);
  EXPECT_FLOAT_EQ(c[2], 2.0);
  EXPECT_FLOAT_EQ(c[3], 3.0);

  
}

TEST(vec4test, scaleTest) {
  
  vec4 a(1.0, 2.0, 3.0, 4.0);
  
  vec4 b = scale(a, 3.0);
  
  EXPECT_FLOAT_EQ(b[0], 3.0);
  EXPECT_FLOAT_EQ(b[1], 6.0);
  EXPECT_FLOAT_EQ(b[2], 9.0);
  EXPECT_FLOAT_EQ(b[3], 12.0);

  
}

TEST(vec4test, maxTest) {
  
  vec4 a(10.0, 2.0, 15.0, 1.0);
  vec4 b(5.0, 5.0, 5.0, 5.0);
  vec4 c(15.0, 1.0, 20.0, 3.0);
  
  vec4 d = max(a, b);
  vec4 e = max(a, c);
  
  EXPECT_FLOAT_EQ(d[0], 10.0);
  EXPECT_FLOAT_EQ(d[1], 5.0);
  EXPECT_FLOAT_EQ(d[2], 15.0);
  EXPECT_FLOAT_EQ(d[3], 5.0);

  
  EXPECT_FLOAT_EQ(e[0], 15.0);
  EXPECT_FLOAT_EQ(e[1], 2.0);
  EXPECT_FLOAT_EQ(e[2], 20.0);
  EXPECT_FLOAT_EQ(e[3], 3.0);

  
}

TEST(vec4test, minTest) {
  
  vec4 a(10.0, 2.0, 15.0, 1.0);
  vec4 b(5.0, 5.0, 5.0, 5.0);
  vec4 c(15.0, 1.0, 20.0, 3.0);
  
  vec4 d = min(a, b);
  vec4 e = min(a, c);
  
  EXPECT_FLOAT_EQ(d[0], 5.0);
  EXPECT_FLOAT_EQ(d[1], 2.0);
  EXPECT_FLOAT_EQ(d[2], 5.0);
  EXPECT_FLOAT_EQ(d[3], 1.0);

  
  EXPECT_FLOAT_EQ(e[0], 10.0);
  EXPECT_FLOAT_EQ(e[1], 1.0);
  EXPECT_FLOAT_EQ(e[2], 15.0);
  EXPECT_FLOAT_EQ(e[3], 1.0);

  
}

TEST(vec4test, cmpTest) {
  
  vec4 a(10.0, 2.0, 15.0, 21.0);
  vec4 b(5.0 + 5.0, 1.0 + 1.0, 7.5 + 7.5, 10.5 + 10.5);
  
  vec4 c(1000000.0, 500000.0, 1500000.0, 75000.0);
  vec4 d(100000.0 * 10.0, 50000.0 * 10.0, 150000.0 * 10.0, 75.0 * 1000.0);
  
  
  EXPECT_TRUE(cmp(a,a));
  EXPECT_TRUE(cmp(a,b));
  EXPECT_TRUE(cmp(b,a));
  EXPECT_TRUE(cmp(b,b));
  
  EXPECT_TRUE(cmp(c,c));
  EXPECT_TRUE(cmp(d,d));
  EXPECT_TRUE(cmp(c,d));
  EXPECT_TRUE(cmp(d,c));
  
}

TEST(vec4test, cmpNearZeroTest) {
  
  vec4 a(2.0, 2.0, 2.0, 2.0);
  vec4 b(1.0, 1.0, 1.0, 1.0);
  
  vec4 c = a - b;
  c = c - b;
  
  vec4 d; //Zero Constructor
  
  EXPECT_TRUE(cmp(c,d));
  
}

TEST(vec4test, lerpTest) {
  
  vec4 a(1.0, 1.0, 1.0, 1.0);
  vec4 b(2.0, 3.0, 4.0, 5.0);
  vec4 c(1.5, 2.0, 2.5, 3.0);
  
  vec4 d;
  d = lerp(a, b, 0.0);
  EXPECT_TRUE(cmp(a,d));
  
  d = lerp(a, b, 1.0);
  EXPECT_TRUE(cmp(b, d));
  
  d = lerp(a, b, 0.5);
  EXPECT_TRUE(cmp(c, d));
  
}

TEST(mat4test, constructorNoArgs) {

  mat4 m;

  vec4 a = m[0].copy();
  vec4 b = m[1].copy();
  vec4 c = m[2].copy();
  vec4 d = m[3].copy();
  
  EXPECT_TRUE(cmp(a, vec4(1.0, 0, 0, 0)));
  EXPECT_TRUE(cmp(b, vec4(0, 1.0, 0, 0)));
  EXPECT_TRUE(cmp(c, vec4(0, 0, 1.0, 0)));
  EXPECT_TRUE(cmp(d, vec4(0, 0, 0, 1.0)));
  
}

TEST(mat4test, constructor4vecs) {
  
  vec4 x(1.0, 2.0, 3.0, 4.0);
  vec4 y(5.0, 5.0, 5.0, 5.0);
  vec4 z(6.0, 7.0, 8.0, 9.0);
  vec4 w(10.0, 10.0, 10.0, 1.0);
  
  mat4 m(x, y, z, w);
  
  vec4 a = m[0].copy();
  vec4 b = m[1].copy();
  vec4 c = m[2].copy();
  vec4 d = m[3].copy();
  
  EXPECT_TRUE(cmp(a, x));
  EXPECT_TRUE(cmp(b, y));
  EXPECT_TRUE(cmp(c, z));
  EXPECT_TRUE(cmp(d, w));

}

TEST(mat4test, to_stringTest) {
  
  vec4 x(1.0, 2.0, 3.0, 4.0);
  vec4 y(5.0, 5.0, 5.0, 5.0);
  vec4 z(6.0, 7.0, 8.0, 9.0);
  vec4 w(10.0, 10.0, 10.0, 1.0);
  
  mat4 m(x, y, z, w);
  
  
  EXPECT_EQ( m.to_string(),
             x.to_string() + ";\n" +
             y.to_string() + ";\n" +
             z.to_string() + ";\n" +
             w.to_string() );
  
}

/*
mat4 copy();


vec4 operator*(const matt4& m, const vec4& v); //right multiplication
vec4 operator*(const vec4& v, const mat4& m); //left multiplication
mat4 operator*(const mat4& m, const mat4& v); //mat4 x mat4 multiplication
*/

TEST(mat4test, rightMultiplicationIdentityTest) {
  
  mat4 m;
  vec4 x(9.0, 1.0, 15.0, 5.0);
  
  vec4 y = m * x; //right multiplication by identity
  
  EXPECT_TRUE( cmp(x, y) );
  
}

TEST(mat4test, rightMultiplicationEigenTest) {
  
  mat4 m( vec4(2.0, 0, 0, 0),
          vec4(0, 3.0, 0, 0),
          vec4(0, 0, 4.0, 0),
          vec4(0, 0, 0, 5.0) );
  
  vec4 y = m * vec4(6.0, 7.0, 8.0, 9.0);
  
  EXPECT_TRUE( cmp(y, vec4(12.0, 21.0, 32.0, 45.0)));
  
}
TEST(mat4test, leftMultiplicationIdentityTest) {
  
  mat4 m;
  vec4 x(9.0, 1.0, 15.0, 5.0);
  
  vec4 y = x * m; //left multiplication by identity
  
  EXPECT_TRUE( cmp(x, y) );
  
}

TEST(mat4test, leftMultiplicationEigenTest) {
  
  mat4 m( vec4(2.0, 0, 0, 0),
          vec4(0, 3.0, 0, 0),
          vec4(0, 0, 4.0, 0),
          vec4(0, 0, 0, 5.0) );
  
  vec4 y = vec4(6.0, 7.0, 8.0, 9.0) * m;
  
  EXPECT_TRUE( cmp(y, vec4(12.0, 21.0, 32.0, 45.0)));
  
}

TEST(mat4test, matrixMatrixMultiplicationTest) {
  
  //A is upper triangular (remember! column major)
  mat4 A( vec4(1.0, 0, 0, 0),
          vec4(0, 2.0, 0, 0),
          vec4(1.0, 0, 3.0, 0),
          vec4(2.0, 1.0, 0, 4.0) );

  //B is not
  mat4 B( vec4(1.0, 1.0, 1.0, 1.0),
          vec4(1.0, 0, 0, 2.0),
          vec4(2.0, 0, 0, 1.0),
          vec4(1.0, 2.0, 2.0, 1.0) );

  //C is really not
  mat4 C( vec4(4.0, 3.0, 3.0, 4.0),
          vec4(5.0, 2.0, 0, 8.0),
          vec4(4.0, 1.0, 0, 4.0),
          vec4(5.0, 5.0, 6.0, 4.0) );

  mat4 D = A * B;
  
  EXPECT_TRUE(cmp(D[0], C[0]));
  EXPECT_TRUE(cmp(D[1], C[1]));
  EXPECT_TRUE(cmp(D[2], C[2]));
  EXPECT_TRUE(cmp(D[3], C[3]));
  
}

TEST(transformationTest, getTranslationMatrixTest) {
  
  mat4 A = getTranslationMatrix( vec3(1.0, 0, 0) );
  mat4 B = getTranslationMatrix( vec3(0, 1.0, 0) );
  mat4 C = getTranslationMatrix( vec3(0, 0, 1.0) );

  vec4 a(1.0, 3.0, 5.0, 1.0);
  vec4 b(1.0, 3.0, 5.0, 1.0);
  vec4 c(1.0, 3.0, 5.0, 1.0);
  
  vec4 d = A * a;
  vec4 e = B * b;
  vec4 f = C * c;
  
  EXPECT_FLOAT_EQ( d[0], 2.0);
  EXPECT_FLOAT_EQ( d[1], 3.0);
  EXPECT_FLOAT_EQ( d[2], 5.0);
  EXPECT_FLOAT_EQ( d[3], 1.0);
  
  EXPECT_FLOAT_EQ( e[0], 1.0);
  EXPECT_FLOAT_EQ( e[1], 4.0);
  EXPECT_FLOAT_EQ( e[2], 5.0);
  EXPECT_FLOAT_EQ( e[3], 1.0);
  
  EXPECT_FLOAT_EQ( f[0], 1.0);
  EXPECT_FLOAT_EQ( f[1], 3.0);
  EXPECT_FLOAT_EQ( f[2], 6.0);
  EXPECT_FLOAT_EQ( f[3], 1.0);
  
  mat4 G = getTranslationMatrix( vec3(3.0, 0, 0) );
  mat4 H = getTranslationMatrix( vec3(0, 7.0, 0) );
  mat4 I = getTranslationMatrix( vec3(0, 0, 11.0) );
  
  vec4 g(1.0, 3.0, 5.0, 1.0);
  vec4 h(1.0, 3.0, 5.0, 1.0);
  vec4 i(1.0, 3.0, 5.0, 1.0);
  
  vec4 j = G * g;
  vec4 k = H * h;
  vec4 l = I * i;
  
  EXPECT_FLOAT_EQ( j[0], 4.0);
  EXPECT_FLOAT_EQ( j[1], 3.0);
  EXPECT_FLOAT_EQ( j[2], 5.0);
  EXPECT_FLOAT_EQ( j[3], 1.0);
  
  EXPECT_FLOAT_EQ( k[0], 1.0);
  EXPECT_FLOAT_EQ( k[1], 10.0);
  EXPECT_FLOAT_EQ( k[2], 5.0);
  EXPECT_FLOAT_EQ( k[3], 1.0);
  
  EXPECT_FLOAT_EQ( l[0], 1.0);
  EXPECT_FLOAT_EQ( l[1], 3.0);
  EXPECT_FLOAT_EQ( l[2], 16.0);
  EXPECT_FLOAT_EQ( l[3], 1.0);
  
  vec4 m = G * H * I * g;
  
  EXPECT_FLOAT_EQ( m[0], 4.0);
  EXPECT_FLOAT_EQ( m[1], 10.0);
  EXPECT_FLOAT_EQ( m[2], 16.0);
  EXPECT_FLOAT_EQ( m[3], 1.0);
  
}

TEST(transformationTest, rotationDummyTest) {
  
  mat4 r = getRotationMatrix( vec4(0, 0, 0, 0) );
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ( i == j) {
        EXPECT_FLOAT_EQ(r[i][j], 1.0);
      }
      else{
        EXPECT_FLOAT_EQ(r[i][j], 0);
      }
    }
  }
  
}

TEST(transformationTest, getScaleMatrixTest) {
  
  mat4 s = getScaleMatrix( vec3(1.0, 5.0, 3.0) );
  
  EXPECT_TRUE( cmp(s[0], vec4(1.0, 0, 0, 0)) );
  EXPECT_TRUE( cmp(s[1], vec4(0, 5.0, 0, 0)) );
  EXPECT_TRUE( cmp(s[2], vec4(0, 0, 3.0, 0)) );
  EXPECT_TRUE( cmp(s[3], vec4(0, 0, 0, 1.0)) );
  
}

//Could use tests for non symmetric (also non diagonal) matrices

int main(int argc, char **argv) {
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}
