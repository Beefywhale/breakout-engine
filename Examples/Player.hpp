#pragma once

#include "../Map/Actor.hpp"
#include "../Map/Map.hpp"
#include <string>

class Player: public Actor {
public:

    // default constructor
    Player() {}

	Player(char* value, int x, int y, Color color, Map* map) : Actor(value, x, y, color) { currentMap = map; currentMap->addActor(this); }
    
    void update(const char* key) override;
    void safeMove(int x, int y);

private:
	Map* currentMap;
};