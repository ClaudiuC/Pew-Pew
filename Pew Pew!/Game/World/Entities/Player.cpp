//
//  Player.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#include "Player.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace pew { namespace world {
  
  // This looks ridiculous right now, but we'll have multiple
  // textures for the player
  resources::Textures::ID toTextureID(Player::Type type) {
    switch (type) {
      case Player::Spaceship:
        return resources::Textures::Spaceship;
        
    }
    return resources::Textures::Spaceship;
  }

  Player::Player(Type type, const resources::TextureHolder& textures) :
    mType(type),
    mSprite(textures.get(toTextureID(type))) {
      
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
  }

  void Player::drawCurrent(sf::RenderTarget& target,
                           sf::RenderStates states) const {
    target.draw(mSprite, states);
  }

} }