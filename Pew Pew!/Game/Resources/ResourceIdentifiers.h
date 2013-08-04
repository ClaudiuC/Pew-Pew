//
//  ResourceIdentifiers.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__ResourceIdentifiers_h
#define Pew_Pew__ResourceIdentifiers_h

// Forward declaration of SFML classes
namespace sf {
	class Texture;
}

namespace pew { namespace resources {
  
  namespace Textures {
    enum ID {
      Spaceship,
      UFO,
      Galaxy,
    };
  }

  // Forward declaration and a few type definitions
  template <typename Resource, typename Identifier>
  class ResourceHolder;

  typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

} }

#endif
