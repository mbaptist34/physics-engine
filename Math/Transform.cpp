//
//  Transform.cpp
//  
//
//  Created by Matthew Baptist on 4/21/17.
//
//

#include "Transform.hpp"

/*
 - scaling is initialized to 1.0, which corresponds to no scaling.
 - it initializes to null as the transform has no parent
 - parent initializes to 0 (null) as the transform has no parent
 - current initializes to true as the local to world matrix starts as identity
*/
  
Transform::Transform() {

  scaling = vec3(1.0, 1.0, 1.0);
  //it = NULL;
  //orientation is set to up
  //parent = 0;
  
  current = true;
  
}

Transform::~Transform() {
  
  /* Emptyyyyy */
}

/**
  - scaling is initialized , which corresponds to no scaling.
  - it initializes to null as the transform has no parent
  - parent initializes to 0 (null) as the transform has no parent
  - current initializes to true as the local to world matrix starts as identity
  - position is set to the passed position.
*/
  
Transform::Transform(const vec3& position /*, const quat& orientation */) {

  this->scaling = vec3(1.0, 1.0, 1.0);
  //it = NULL;
  //orientation is set to up
  //parent = 0;
  
  this->position = position.copy();
  
  current = true;
    
}

/**
 - it initializes to null as the transform has no parent
 - parent initializes to 0 (null) as the transform has no parent
 - current initializes to true as the local to world matrix starts as identity
 - position is set to the passed position.
 */

Transform::Transform(const vec3& position /*, quat orientation */, const vec3& scaling) {
  
  this->scaling = scaling.copy();
  //it = NULL;
  //orientation is set to up
  //parent = 0;
  
  this->position = position.copy();
  
  current = true;
  
}

/**
 Places the transform into a Transform heirarchy as the child of p.
 
  @param p A transform smart pointer to the parent Transform
 */
  
void Transform::setParent(MMPtr<Transform> p ) {
  
  assert( p != 0 );
  
  //Remove this from the existing parent
  if (this->parent != 0) {
    this->parent->children.erase( this->it );
    this->parent = 0;
  }
  this->parent = p; //Set parent link
  
  p->children.push_back( MMPtr<Transform>(this) ); //Push this to the parent's child list
  this->it = std::next(p->children.end(), -1); //Get the iterator corresponding to its position in the list
  
}

/**
 Returns the parent transform of the transform.
 
 @return An MMPtr<Transform> if the node has a parent, else NULL.
  */

MMPtr<Transform> Transform::getParent() {
  
  return MMPtr<Transform>(parent);
  
}

/**
 Returns an iterator for the transform's children.
 
 @return An std::list< MMPtr<Transform> >::iterator.
 */

std::list< MMPtr<Transform> >::const_iterator Transform::getChildrenIterator() {
  
 return this->children.cbegin();
  
}

/**
 Sets the transform as the parent of c in a Transform heirarchy.
 
 @param c A transform smart pointer to the child Transform
 */
  
void Transform::addChild( MMPtr<Transform> c ) {
  
  assert( c != 0 );
  
  if (c->parent != 0) {
    c->parent->children.erase( c->it );
    c->parent = 0;
  }

  c->parent = this; //Set child's parent link
  
  this->children.push_back( c ); //Push the child to the back of the parent's child list
  c->it = std::next(this->children.end(), -1); //Get the iterator corresponding the the childs position in the list
  
}

/**
 Returns the position vector of the Transform in local space (world space if the Transform has no parent)
 
 @return returns a vec3 which gives the position.
 */

vec3 Transform::getPosition() {
  
  return position;
  
}

//quat getOrientation();

/**
 Translates the position in local space by t
 
 @param t A vec3 that gives the translation amount
 */
  
void Transform::translate(const vec3& t) {
  
  position = position + t;
  
  current = false; //The localToWorld matrix is now old.
  
}

/**
 Changes the scale of the transform
 
 @param s A float that the current scale is multiplied by.
 */

void Transform::scaleBy(vec3 s) {
  
  scaling[0] = scaling[0] * s[0];
  scaling[1] = scaling[1] * s[1];
  scaling[2] = scaling[2] * s[2];
  
  current = false; //The localToWorld matrix is now old.
  
}

void Transform::rotateAround(vec3 axis, float angle) {
 
  //Do nothing..
  
}

  //void rotateBy(quat);

/**
 Checks whether the localToWorld matrix is current.
 
 @return true if the matrix is current, false if a change has been made since
 */

bool Transform::isCurrent() {
  
  return current;
  
}

/**
 Gets the localToWorld matrix of the current Transform
 
 @return A mat4 giving the localToWorld matrix
 */

mat4 Transform::getLocalToWorld() {

  if ( isCurrent() ) {
    return localToWorld;
  }
  else {
    
    //Transform is constructed as follows M = Translate * Rotation * Scale
    
    localToWorld = getTranslationMatrix( position ) * getRotationMatrix( vec4(0,0,0,0) ) * getScaleMatrix( scaling );
    
    //If this is a child it needs to be multiplied by the parent's getLocalToWorld
    if (parent != NULL) {
      localToWorld = localToWorld * parent->getLocalToWorld();
    }
    
    current = true;
    
    return localToWorld;
  }
  
}
