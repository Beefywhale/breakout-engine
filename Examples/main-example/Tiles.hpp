#pragma once

#include "Tile.hpp"

// define all custom tile classes here

// example of a custom tile type
// it's pretty useless but you could have your own with private members and custom functions
class Door : public Tile
{
public:
  // default constructor
  Door(std::string value, int x, int y, Color color, bool solid) : Tile(value, x, y, color, solid) { setType("door"); }
};