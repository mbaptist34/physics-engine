//
//  GameObject.hpp
//  
//
//  Created by Matthew Baptist on 4/19/17.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "../Core/MMObject.h"
#include "../Math/math3.hpp"

class GameObject : MMObject {
  
  static int numObjects = 0;
  static int getNewId();

protected:
  
    GameObject();
    virtual ~GameObject();
  
public:
  
  int id;
  
  bool inWorld;
  
  vec3 position;
  //quat orientation; For Later
  
  bool operator==(const GameObject& b);
  
};

#endif /* GameObject_hpp */
