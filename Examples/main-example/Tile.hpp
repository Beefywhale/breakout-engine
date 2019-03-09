#pragma once

#include "../../Map/Actor.hpp"
#include <string>

class Tile : public Actor
{
public:
  // default constructor.
  Tile(std::string value, int x, int y, Color color, bool solid) : Actor(value, x, y, color)
  {
    solidness = solid;
    type = "";
  }

  void setSolid(bool solid);
  void setType(std::string newType);

  bool isSolid() { return solidness; }
  std::string getType() { return type; }

private:
  bool solidness;
  std::string type;
};
