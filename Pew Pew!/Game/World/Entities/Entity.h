//
//  Entity.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__Entity_h
#define Pew_Pew__Entity_h

#include "SceneNode.h"

namespace pew { namespace world {
  
  class Entity : public SceneNode {
    public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;
    
    private:
    virtual void updateCurrent(sf::Time dt);
    
    private:
    sf::Vector2f mVelocity;
  };

} }

#endif
