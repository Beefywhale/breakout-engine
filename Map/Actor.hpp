#pragma once
#include "../Base/Color.hpp"

struct positionData {
    int x; int y;
};

class Actor {
public:

    // default constructor
    Actor() {}

    // create an actor with a value, position and color
    Actor(char* value, int x, int y, Color color);

    // move the Actor from current position by adding to it.
    void move(int x, int y);
    // move the Actor to any x,y coordinate.
    void setPosition(int x, int y);

    positionData getPosition() { return position; }
    char* getValue() { return val; }
    Color getColor() { return colors; }

private:
    positionData position;
    char* val;
    Color colors;
};
