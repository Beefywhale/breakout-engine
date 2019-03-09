#include "Tile.hpp"

Tile::Tile(std::string value, int x, int y, Color color, bool solid) : Actor(value, x, y, color)
{
    solidness = solid;
    // set the type to nothing because Tile should be the default
    type = "";
}

void Tile::setSolid(bool solid)
{
    solidness = solid;
}

void Tile::setType(std::string newType)
{
    type = newType;
}
