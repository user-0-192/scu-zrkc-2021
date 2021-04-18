#include "Obj.h"

Object::Object(uint id, uint grid, uint lon, uint lat)
  :id_(id), grid_(grid), lon_(lon), lat_(lat) {}

uint Object::getId() const { return id_; }

uint Object::getGrid() const { return grid_; }

uint Object::getLon() const { return lon_;  }

uint Object::getLat() const { return lat_;  }

bool Object::operator < (const Object& obj)
{ return this->grid_ > obj.grid_; }

std::ostream& operator << (std::ostream& os,const Object& obj)
{
  os << obj.getId() << ',' << obj.getGrid() << ',' << obj.getLon() << ',' << obj.getLat();
  return os;
}