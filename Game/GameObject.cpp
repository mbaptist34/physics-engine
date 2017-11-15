//
//  GameObject.cpp
//  
//
//  Created by Matthew Baptist on 4/19/17.
//
//

#include "GameObject.hpp"

static int GameObject::getNewId() {
  
  return numObjects++;
  
}

GameObject::GameObject() {
 
  this->id = getNewId();
  this->inWorld = true; //defaults to true.
  
}

virtual GameObject::~GameObject() {
  
  //Empty for inheritance purposes.
  
}

bool GameObject::operator==(const GameObject& b) {
  
  if (this->id == b.id) {
    return true;
  }
  else {
    return false;
  }
  
}
