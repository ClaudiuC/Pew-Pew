//
//  Player.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#include "Spaceship.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace Pew {
  
  // This looks ridiculous right now, but we'll have multiple
  // textures for the player
  Textures::ID toTextureID(Spaceship::Type type) {
    switch (type) {
      case Spaceship::DefaultShip:
        return Textures::DefaultShip;
        
    }
    return Textures::DefaultShip;
  }
 
  Spaceship::Spaceship(Type type, const TextureHolder& textures) :
    mType(type),
    mSprite(textures.get(toTextureID(type))) {
      
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
  }

  void Spaceship::drawCurrent(sf::RenderTarget& target,
                           sf::RenderStates states) const {
    target.draw(mSprite, states);
  }

  unsigned int Spaceship::getCategory() const {
    switch (mType) {
      case DefaultShip:
        return Category::PlayerSpaceship;
         
      default:
        return Category::EnemyUFO;
    }
  }
  
}