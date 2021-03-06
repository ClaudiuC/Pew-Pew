//
//  World.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <algorithm>
#include <cmath>

namespace Pew {
   
  World::World(sf::RenderWindow& window):
      mWindow(window),
      mWorldView(window.getDefaultView()),
      mTextures(),
      mSceneGraph(),
      mSceneLayers(),
      mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
      mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f),
      mScrollSpeed(-50.f),
      mPlayer(nullptr) {
        
    loadTextures();
    buildScene();
    
    // Prepare the view
    mWorldView.setCenter(mSpawnPosition);
  }

  void World::update(sf::Time deltaTime) {
    // Scroll the world, reset player velocity
    mWorldView.move(0.f, mScrollSpeed * deltaTime.asSeconds());
    mPlayer->setVelocity(0.f, 0.f);
    
    // Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
    while (!mCommandQueue.isEmpty()) {
      mSceneGraph.onCommand(mCommandQueue.pop(), deltaTime);
    }
    adaptPlayerVelocity();
    
    // Regular update step, adapt position (correct if outside view)
    mSceneGraph.update(deltaTime);
    adaptPlayerPosition();
  }

  void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
  }

  void World::loadTextures() {
    mTextures.load(Textures::DefaultShip, "Assets/Graphics/player.png");
    mTextures.load(Textures::UFO, "Assets/Graphics/ufo.png");
    mTextures.load(Textures::Galaxy, "Assets/Graphics/galaxy.gif");
  }

  void World::buildScene() {
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i) {
      SceneNode::Ptr layer(new SceneNode());
      mSceneLayers[i] = layer.get();
      
      mSceneGraph.attachChild(std::move(layer));
    }
    
    // Prepare the tiled background
    sf::Texture& texture = mTextures.get(Textures::Galaxy);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);
    
    // Add the background sprite to the scene
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Background]->attachChild(std::move(backgroundSprite));
    
    // Add player's aircraft
    std::unique_ptr<Spaceship> leader(new Spaceship(Spaceship::DefaultShip, mTextures));
    mPlayer = leader.get();
    mPlayer->setPosition(mSpawnPosition);
    mPlayer->setVelocity(40.f, mScrollSpeed);
    mSceneLayers[Air]->attachChild(std::move(leader));
  }

  void World::adaptPlayerPosition() {
    // Keep player's position inside the screen bounds, at least borderDistance units from the border
    sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
    const float borderDistance = 40.f;
    
    sf::Vector2f position = mPlayer->getPosition();
    position.x = std::max(position.x, viewBounds.left + borderDistance);
    position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
    position.y = std::max(position.y, viewBounds.top + borderDistance);
    position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
    mPlayer->setPosition(position);
  }
  
  void World::adaptPlayerVelocity() {
    sf::Vector2f velocity = mPlayer->getVelocity();
    
    // If moving diagonally, reduce velocity (to have always same velocity)
    if (velocity.x != 0.f && velocity.y != 0.f) {
      mPlayer->setVelocity(velocity / std::sqrt(2.f));
    } 
    
    // Add scrolling velocity
    mPlayer->accelerate(0.f, mScrollSpeed);
  }
  
  CommandQueue& World::getCommandQueue() {
    return mCommandQueue;
  }
}