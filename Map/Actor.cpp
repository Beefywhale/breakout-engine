#include "Actor.hpp"

Actor::Actor(std::string value, int x, int y, Color color)
{
    val = value;
    position.x = x;
    position.y = y;
    colors = color;
}

void Actor::move(int x, int y)
{
    position.x = position.x + x;
    position.y = position.y + y;
}

void Actor::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void Actor::setValue(std::string newVal)
{
    val = newVal;
}