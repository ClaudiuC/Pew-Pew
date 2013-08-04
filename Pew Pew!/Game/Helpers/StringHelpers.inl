//
//  StringHelpers.inl
//  Pew Pew!
//
//  Created by Claudiu Ceia on 8/4/13.
//  Copyright (c) 2013 Claudiu Ceia. All rights reserved.
//

template <typename T>
std::string toString(const T& value) {
  std::stringstream stream;
  stream << value;
  return stream.str();
}