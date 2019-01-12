#pragma once
#include "../Map/Actor.hpp"
#include <string>

class Player: public Actor {
public:

    // default constructor
    Player() {}

    Player(char* value, int x, int y, Color color) : Actor(value, x, y, color) {};

    void update(const char* key) override;

};