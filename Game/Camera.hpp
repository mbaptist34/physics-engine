//
//  Camera.hpp
//  
//
//  Created by Matthew Baptist on 4/20/17.
//
//

#ifndef Camera_hpp
#define Camera_hpp

#include "../Math/math3.hpp"
#include "../Game/GameObject.hpp"
#include "../Math/Transform.hpp"
#include "../Core/MMPtr.h"

class Camera : GameObject {
  
  mat4 perspective;
  mat4 worldToViewMatrix;
  
  vec3 up;
  
  MMPtr<Transform> transform;
  
public:
  
  Camera();
  
  mat4 getWorldToViewMatrix();
  void setPerpective();
  
  void lookAtRh(vec3 target, vec3 up);
  
  
  
};


#endif /* Camera_hpp */
