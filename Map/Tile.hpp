#pragma once

#include "Actor.hpp"

class Tile: public Actor {
public:

    // default constructor.
    Tile(char* value, int x, int y, Color color, bool solid): Actor(value, x, y, color) { solidness = solid; }

    void setSolid(bool solid);

    bool isSolid() { return solidness; }

private:
    bool solidness;

};
