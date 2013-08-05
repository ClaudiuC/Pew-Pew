//
//  SpriteNode.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__SpriteNode_h
#define Pew_Pew__SpriteNode_h

#include "SceneNode.h"

#include <SFML/Graphics/Sprite.hpp>

namespace Pew {

  class SpriteNode : public SceneNode {
    public:
      explicit SpriteNode(const sf::Texture& texture);
      SpriteNode(const sf::Texture& texture,
                 const sf::IntRect& textureRect);
      
    private:
      virtual void drawCurrent(sf::RenderTarget& target,
                               sf::RenderStates states) const;
    
    private:
      sf::Sprite mSprite;
  };

}

#endif
