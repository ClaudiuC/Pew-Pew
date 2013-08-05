//
//  SpriteNode.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#include "SpriteNode.h"

#include <SFML/Graphics/RenderTarget.hpp>

namespace Pew {
  
  SpriteNode::SpriteNode(const sf::Texture& texture) : mSprite(texture) {
  } 
  
  // TODO: How does one format C++ nicely? :/
  SpriteNode::SpriteNode(const sf::Texture& texture,
                         const sf::IntRect& textureRect) :
      mSprite(texture, textureRect) {
  }

  void SpriteNode::drawCurrent(sf::RenderTarget& target,
                               sf::RenderStates states) const {
    target.draw(mSprite, states);
  }

}