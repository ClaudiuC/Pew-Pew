//
//  CommandQueue.cpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#include "CommandQueue.h"

#include "CommandQueue.h"
#include "SceneNode.h"

namespace Pew {
   
  void CommandQueue::push(const Command& command) {
    mQueue.push(command);
  }

  Command CommandQueue::pop() {
    Command command = mQueue.front();
    mQueue.pop();
    return command;
  }

  bool CommandQueue::isEmpty() const {
    return mQueue.empty();
  }

}