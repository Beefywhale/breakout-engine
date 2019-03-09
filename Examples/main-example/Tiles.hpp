#pragma once

#include "Tile.hpp"

// Define all custom tile classes here

class Door : public Tile
{
public:
  // default constructor.
  Door(std::string value, int x, int y, Color color, bool solid) : Tile(value, x, y, color, solid) { setType("door"); }
};