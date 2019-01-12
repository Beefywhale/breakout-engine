#pragma once

#include <map>
#include <vector>
#include "Tile.hpp"
#include "../Base/Color.hpp"

class Map {
public:

    // default constructor
    Map();

    // get the Tile at a give x,y
    Tile getTileAt(int x, int y);
    // get all the current Tiles in the Map
    std::map<std::pair<int, int>, Tile> getTiles() { return tiles; }
    std::vector<Actor*> getActors() { return actors; }

    void addActor(Actor* actor);
    bool isTileAt(int x, int y);

private:
    std::map<std::pair<int, int>, Tile> tiles;
    std::vector<Actor*> actors;

};
