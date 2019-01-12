#pragma once
#include <map>
#include <vector>
#include "Tile.hpp"
#include "Actor.hpp"
#include "../Base/Color.hpp"

class Map {
public:

    // default constructor
    Map();

    void addActor(Actor* newActor);

    // get the Tile at a give x,y
    Tile getTileAt(int x, int y);
    // get all the current Tiles in the Map
    std::map<std::pair<int, int>, Tile> getTiles() { return tileMap; }
    std::vector<Actor*> getActors() { return actors; }

private:
    std::map<std::pair<int, int>, Tile> tileMap;
    std::vector<Actor*> actors;

};
