//
//  SceneNode.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__SceneNode_h
#define Pew_Pew__SceneNode_h

#include "Category.h"
#include "Command.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

namespace Pew {

  //struct Command;
  
  class SceneNode :
    public sf::Transformable,
    public sf::Drawable,
    private sf::NonCopyable {

    public:
      typedef std::unique_ptr<SceneNode> Ptr;
    
    public:
      SceneNode();
      
      void attachChild(Ptr child);
      Ptr detachChild(const SceneNode& node);
      
      void update(sf::Time dt);
      
      sf::Vector2f getWorldPosition() const;
      sf::Transform getWorldTransform() const;
    
      void onCommand(const Command& command, sf::Time deltaTime);
      virtual unsigned int getCategory() const;
      
    private:
      virtual void updateCurrent(sf::Time dt);
      void updateChildren(sf::Time dt);
      
      virtual void draw(sf::RenderTarget& target,
                        sf::RenderStates states) const;
        
      virtual void drawCurrent(sf::RenderTarget& target,
                               sf::RenderStates states) const;
        
      void drawChildren(sf::RenderTarget& target,
                        sf::RenderStates states) const;
    
    private:
      std::vector<Ptr> mChildren;
      SceneNode* mParent;
  };
  
}

#endif
