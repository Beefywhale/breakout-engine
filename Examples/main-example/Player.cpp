#include "Player.hpp"

Player::Player(std::string value, int x, int y, Color color, Engine *currentEngine) : Actor(value, x, y, color)
{
    // set the private engine member to the passed Engine*
    engine = currentEngine;
}

void Player::update()
{
    // wasd movement
    // for each key that's down move the player in the specific direction
    // safeMove only moves the player if there is no collision or specific events with other tile types
    if (engine->isKeyDown("W"))
    {
        safeMove(0, -1);
    }
    else if (engine->isKeyDown("S"))
    {
        safeMove(0, 1);
    }
    if (engine->isKeyDown("A"))
    {
        safeMove(-1, 0);
    }
    else if (engine->isKeyDown("D"))
    {
        safeMove(1, 0);
    }
}

void Player::safeMove(int x, int y)
{
    // if there is a tile at the x and y then allow the player to attempt move there
    // if there isn't then the player does nothing
    // we assume the layer is "tiles" here because that's how we have the example setup but it could be anything depending on the needed situation
    if (engine->getMap()->getLayers()["tiles"]->isActorAt(position.x + x, position.y + y))
    {
        // get the Actor (some sort of tile) at the x and y
        auto tileTemp = engine->getMap()->getLayers()["tiles"]->getActorAt(position.x + x, position.y + y);
        // cast the Actor to Tile because of the "tiles" layer
        auto tile = static_cast<Tile *>(tileTemp);

        // if the tile isn't solid then allow the player to move there
        if (!tile->isSolid())
        {
            move(x, y);
        }
        else
        {
            // if the tile is solid log it to the console and don't allow the player to move
            engine->getLogger()->info("Player collided with a Tile at: " + std::to_string(tile->getPosition().x) + "," + std::to_string(tile->getPosition().y));

            // if the type of the tile is a door then cast the Tile to a Door and then "open" the door
            // this is really just a basic example of what you could do
            if (tile->getType() == std::string("door"))
            {
                auto door = static_cast<Door *>(tile);
                door->setSolid(false);
                door->setValue("=");
            }
        }
    }
}
