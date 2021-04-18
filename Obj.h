#ifndef OBJ_H
#define ObJ_H

#pragma once

#include <stdint.h>
#include <iostream>

using uint = uint32_t;

class Object
{
  private:
  uint  id_;
  uint  grid_;
  uint  lon_;
  uint  lat_;

  public:
  Object() = default;
  Object(uint id, uint grid, uint lon, uint lat);
  Object(const Object&) = default;
  Object(Object&&) = default;

  uint getId() const;
  uint getGrid() const;
  uint getLon() const;
  uint getLat() const;

  Object& operator = (const Object& ) = default;
  bool operator < (const Object& obj);
  friend std::ostream& operator << (std::ostream& os, const Object& obj); 
};

#endif //OBJ_H