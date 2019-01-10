#pragma once
#include "Actor.hpp"
#include "../Base/Color.hpp"

class Tile: public Actor {
public:

    // default constructor
    Tile() {}

    // create a tile with a value and position
    Tile(char* value, int x, int y, Color color) : Actor(value, x, y, color) {}

};
