//
//  World.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__World_h
#define Pew_Pew__World_h

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Player.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>


// Forward declaration
namespace sf {
	class RenderWindow;
}

namespace pew { namespace world {
  
  class World : private sf::NonCopyable {
    public:
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();
    
    private:
    void loadTextures();
    void buildScene();
    
    private:
    enum Layer {
      Background,
      Air,
      LayerCount
    };
    
    private:
    sf::RenderWindow& mWindow;
    sf::View mWorldView;
    resources::TextureHolder mTextures;
    
    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount>	mSceneLayers;
    
    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Player* mPlayer;
  };
  
} }
#endif
