//
//  Transform.hpp
//  
//
//  Created by Matthew Baptist on 4/21/17.
//
//

#ifndef Transform_hpp
#define Transform_hpp


#include "../Math/math3.hpp"
#include "../Core/MMObject.h"
#include "../Core/MMPtr.h"
#include "../Core/Logger.h"

#include <list>

class Transform : public MMObject {
  
  AUTO_SIZE
  
  vec3 position;
  //quat orientation;
  vec3 scaling;
  
  std::list< MMPtr<Transform> > children;
  std::list< MMPtr<Transform> >::iterator it;
  
  Weak_MMPtr<Transform> parent;
  
  mat4 localToWorld;
  bool current;
  
public:
  
  Transform();
  Transform(const vec3& position /*, const quat& orientation */ );
  Transform(const vec3& position /*, const quat& orientation */, const vec3& scaling);
  ~Transform();
  
  void setParent( MMPtr<Transform> p );
  MMPtr<Transform> getParent();
  void addChild( MMPtr<Transform> c );
  std::list< MMPtr<Transform> >::const_iterator getChildrenIterator();
  
  vec3 getPosition();
  //quat getOrientation();
  
  void translate(const vec3 & t);
  void scaleBy(vec3 s);
  void rotateAround(vec3 axis, float angle); //rotation axis and angle in radians
  //void rotateBy(quat);
  
  bool isCurrent();
  mat4 getLocalToWorld();
  
};


#endif /* Transform_hpp */
