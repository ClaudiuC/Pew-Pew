//
//  World.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace pew { namespace world {
   
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
    // Scroll the world
    mWorldView.move(0.f, mScrollSpeed * deltaTime.asSeconds());
    
    // Move the player sidewards (plane scouts follow the main aircraft)
    sf::Vector2f position = mPlayer->getPosition();
    sf::Vector2f velocity = mPlayer->getVelocity();
    
    // If player touches borders, flip its X velocity
    if (position.x <= mWorldBounds.left + 150.f
        || position.x >= mWorldBounds.left + mWorldBounds.width - 150.f) {
      velocity.x = -velocity.x;
      mPlayer->setVelocity(velocity);
    }
    
    // Apply movements
    mSceneGraph.update(deltaTime);
  }

  void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
  }

  void World::loadTextures() {
    mTextures.load(resources::Textures::DefaultShip, "Assets/Graphics/player.png");
    mTextures.load(resources::Textures::UFO, "Assets/Graphics/ufo.png");
    mTextures.load(resources::Textures::Galaxy, "Assets/Graphics/galaxy.gif");
  }

  void World::buildScene() {
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i) {
      SceneNode::Ptr layer(new SceneNode());
      mSceneLayers[i] = layer.get();
      
      mSceneGraph.attachChild(std::move(layer));
    }
    
    // Prepare the tiled background
    sf::Texture& texture = mTextures.get(resources::Textures::Galaxy);
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
    
    // Add two escorting aircrafts, placed relatively to the main plane
    std::unique_ptr<Spaceship> leftEscort(new Spaceship(Spaceship::DefaultShip, mTextures));
    leftEscort->setPosition(-80.f, 50.f);
    mPlayer->attachChild(std::move(leftEscort));
    std::unique_ptr<Spaceship> rightEscort(new Spaceship(Spaceship::DefaultShip, mTextures));
    rightEscort->setPosition(80.f, 50.f);
    mPlayer->attachChild(std::move(rightEscort));
  }

} }