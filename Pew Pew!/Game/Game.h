//
//  game.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/3/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__game_h
#define Pew_Pew__game_h

#include "World.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace pew {
   
  class Game : private sf::NonCopyable {
    public: 
    Game();
    void run();
    
    private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void updateStatistics(sf::Time elapsedTime);
    
    private:
    static const sf::Time TimePerFrame;
    static const float PlayerSpeed;
     
    sf::RenderWindow mWindow;
    world::World					mWorld;
    
    sf::Font mFont;
		sf::Text mStatisticsText;
		sf::Time mStatisticsUpdateTime;
		std::size_t mStatisticsNumFrames;
    
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
  };

}

#endif
