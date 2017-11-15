//
//  transformTest.cpp
//  
//
//  Created by Matthew Baptist on 4/22/17.
//
//

#include "gtest/gtest.h"
#include "../Math/math3.hpp"
#include "../Math/Transform.hpp"
#include "../Core/MMObject.h"
#include "../Core/MMPtr.h"

TEST(transformTest, constructorNoParam) {
  
  MMPtr<Transform> t = new Transform();
  vec3 pos = t->getPosition();
  
  EXPECT_FLOAT_EQ(pos[0], 0);
  EXPECT_FLOAT_EQ(pos[1], 0);
  EXPECT_FLOAT_EQ(pos[2], 0);

}

TEST(transformTest, constructorTwoParams) {
  
  MMPtr<Transform> t = new Transform(vec3(2.0, 3.0, 5.0)/*, quat() */ );
  vec3 pos = t->getPosition();
  
  EXPECT_FLOAT_EQ(pos[0], 2.0);
  EXPECT_FLOAT_EQ(pos[1], 3.0);
  EXPECT_FLOAT_EQ(pos[2], 5.0);
  
}

TEST(transformTest, constructorThreeParams) {
  
  MMPtr<Transform> t = new Transform(vec3(2.0, 3.0, 5.0)/*, quat() */, vec3(2.0, 2.0, 2.0) );
  vec3 pos = t->getPosition();
  
  EXPECT_FLOAT_EQ(pos[0], 2.0);
  EXPECT_FLOAT_EQ(pos[1], 3.0);
  EXPECT_FLOAT_EQ(pos[2], 5.0);
  
}

TEST(transformTest, setParentTest) {
  
  MMPtr<Transform> t1 = new Transform();
  MMPtr<Transform> t2 = new Transform();
  
  t2->setParent(t1);
  MMPtr<Transform> t3 = t2->getParent();
  
  EXPECT_TRUE( t1 == t3 );
  EXPECT_FALSE( t2 == t3 );
  EXPECT_FALSE( t1 == t2 );
  
  t3 = *(t1->getChildrenIterator());
  
  EXPECT_TRUE( t2 == t3 );
  EXPECT_FALSE( t1 == t3 );
  EXPECT_FALSE( t1 == t2 );

}

TEST(transformTest, addChildTest) {
  
  MMPtr<Transform> t1 = new Transform();
  MMPtr<Transform> t2 = new Transform();
  
  t1->addChild(t2);
  MMPtr<Transform> t3 = t2->getParent();
  
  EXPECT_TRUE( t1 == t3 );
  EXPECT_FALSE( t2 == t3 );
  EXPECT_FALSE( t1 == t2 );
  
  t3 = *(t1->getChildrenIterator());
  
  EXPECT_TRUE( t2 == t3 );
  EXPECT_FALSE( t1 == t3 );
  EXPECT_FALSE( t1 == t2 );
  
}

TEST(transformTest, largeHeirarchyTest) {
 
  MMPtr<Transform> t1 = new Transform();
  MMPtr<Transform> t2 = new Transform();
  MMPtr<Transform> t3 = new Transform();
  MMPtr<Transform> t4 = new Transform();
  MMPtr<Transform> t5 = new Transform();
  MMPtr<Transform> t6 = new Transform();
  MMPtr<Transform> t7 = new Transform();
  MMPtr<Transform> t8 = new Transform();
  
  t2->setParent(t1);
  t3->setParent(t1);
  
  t4->setParent(t2);
  t5->setParent(t2);
  
  t6->setParent(t3);
  t7->setParent(t3);
  
  t8->setParent(t6);
  t8->setParent(t7);
  
  EXPECT_TRUE( t8->getParent() == t7 );
  EXPECT_FALSE( t8->getParent() == t6 );
  
}

TEST(transformTest, isCurrentTest) {
  
  MMPtr<Transform> t1 = new Transform();

  EXPECT_TRUE( t1->isCurrent() );
  
  t1->translate(vec3(1.0, 1.0, 0));
  
  EXPECT_FALSE( t1->isCurrent() );
  
  t1->getLocalToWorld();
  
  EXPECT_TRUE( t1->isCurrent() );
  
  t1->scaleBy(vec3(2.0, 1.0, 1.0));
  
  EXPECT_FALSE( t1->isCurrent() );
  
  t1->getLocalToWorld();
  
  EXPECT_TRUE( t1->isCurrent() );
  
  //t1.rotateAround();
  //EXPECT_FALSE( t1->isCurrent() );
  //t1.getLocalToWorld();
  //EXPECT_TRUE( t1->isCurrent() );
  
}

TEST(transformTest, getLocalToWorldOneTransformTest) {
  
  MMPtr<Transform> t1 = new Transform();
  
  mat4 m = t1.getLocalToWorld();
  
  
  
}

int main(int argc, char **argv) {
  
  LOGGER.Init();
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  MMObject::collectRemainingObjects();
  return 1;
}
