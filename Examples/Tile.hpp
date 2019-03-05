#pragma once

#include "../Map/Actor.hpp"

class Tile : public Actor
{
  public:
    // default constructor.
    Tile(char *value, int x, int y, Color color, bool solid) : Actor(value, x, y, color)
    {
        solidness = solid;
        type = "";
    }

    void setSolid(bool solid);
    void setType(char *newType);

    bool isSolid() { return solidness; }
    char *getType() { return type; }

  private:
    bool solidness;
    char *type;
};
