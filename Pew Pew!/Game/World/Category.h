//
//  Category.h
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__Category_h
#define Pew_Pew__Category_h

namespace Pew {
  
  namespace Category {
    enum Type {
      None = 0,
      Scene = 1 << 0,
      PlayerSpaceship = 1 << 1,
      AlliedSpaceship = 1 << 2,
      EnemyUFO = 1 << 3,
    };
  }
  
}

#endif
