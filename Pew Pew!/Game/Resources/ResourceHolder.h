//
//  ResourceHolder.hpp
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

#ifndef Pew_Pew__ResourceHolder_hpp
#define Pew_Pew__ResourceHolder_hpp

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

namespace pew { namespace resources {
  
  template <typename Resource, typename Identifier>
  class ResourceHolder {
    public:
    void load(Identifier id, const std::string& filename);
    
    template <typename Parameter>
    void load(Identifier id,
              const std::string& filename,
              const Parameter& secondParam);
    
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
    
    private:
    void insertResource(Identifier id,
                        std::unique_ptr<Resource> resource);
    
    
    private:
    std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
  };
  
} }

#include "ResourceHolder.inl"

#endif
