#pragma once

#include "../Map/Actor.hpp"
#include "../Base/Engine.hpp"
#include "Tile.hpp"
#include <string>

class Player: public Actor {
public:

    // default constructor
    Player() {}
    Player(char* value, int x, int y, Color color, Engine* currentEngine): Actor(value, x, y, color) { engine = currentEngine; engine->getMap()->getLayers().at(1)->addActor(this); }

    void update() override;
    void safeMove(int x, int y);

private:
	Engine* engine;
};
