#include "Map.hpp"

Map::Map() {
    for (int i = 0; i < 10; i++) {
        Tile newTile("#", 0, i, Color(255,255,0));
        tileMap[std::make_pair(0,i)] = newTile;
    }
}

void Map::addActor(Actor newActor) {
    actors.push_back(newActor);
}

Tile Map::getTileAt(int x, int y) {
    if (tileMap.find(std::make_pair(x, y)) != tileMap.end()) {
        return tileMap[std::make_pair(x, y)];
    }
}