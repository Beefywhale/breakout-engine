#pragma once
#include <map>
#include "Tile.hpp"
#include "../Base/Color.hpp"

class Map {
public:

    // default constructor
    Map();

    // get the Tile at a give x,y
    Tile getTileAt(int x, int y);
    // get all the curren Tiles in the Map
    std::map<std::pair<int, int>, Tile> getTiles() { return tileMap; }

private:
    std::map<std::pair<int, int>, Tile> tileMap;
};
