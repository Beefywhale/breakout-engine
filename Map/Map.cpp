#include "Map.hpp"

Map::Map() {
    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		Tile newTile("#", j, i, Color(255,255,0));
        	tiles[std::make_pair(j,i)] = newTile;
    	}
        Tile newTile("#", 0, i, Color(255,255,0));
        tiles[std::make_pair(0,i)] = newTile;
    }
}

void Map::addActor(Actor* newActor) {
    actors.push_back(newActor);
}

Tile Map::getTileAt(int x, int y) {
    if (tiles.find(std::make_pair(x, y)) != tiles.end()) {
        return tiles[std::make_pair(x, y)];
    }
}

bool Map::isTileAt(int x, int y) {
	if (tiles.find(std::make_pair(x, y)) != tiles.end()) {
        return true;
    } else {
    	return false;
    }
}