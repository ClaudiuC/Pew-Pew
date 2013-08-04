//
//  Entity.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//
 
#include "Entity.h"

namespace pew { namespace world {

  void Entity::setVelocity(sf::Vector2f velocity) {
    mVelocity = velocity;
  }

  void Entity::setVelocity(float vx, float vy) {
    mVelocity.x = vx;
    mVelocity.y = vy;
  }

  sf::Vector2f Entity::getVelocity() const {
    return mVelocity;
  }

  void Entity::updateCurrent(sf::Time dt) {
    move(mVelocity * dt.asSeconds());
  }

} }