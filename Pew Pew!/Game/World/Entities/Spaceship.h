//
//  Player.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__Spaceship_h
#define Pew_Pew__Spaceship_h

#include "Entity.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

namespace Pew {

  class Spaceship : public Entity {
    public:
      enum Type {
        DefaultShip,
      };
    
    public:
      Spaceship(Type type, const TextureHolder& textures);
      
      virtual void drawCurrent(sf::RenderTarget& target,
                               sf::RenderStates states) const;
      virtual unsigned int	getCategory() const;
      
    private:
      Type mType;
      sf::Sprite mSprite;
  };
   
}

#endif
