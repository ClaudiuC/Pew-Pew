//
//  CommandQueue.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__CommandQueue_h
#define Pew_Pew__CommandQueue_h

#include "Command.h"

#include <queue> 

namespace Pew {

  class CommandQueue {
    public:
      void push(const Command& command);
      Command pop();
      bool isEmpty() const;
    
    private:
      std::queue<Command>			mQueue;
  };

}

#endif
