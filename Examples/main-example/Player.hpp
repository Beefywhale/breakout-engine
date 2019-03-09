#pragma once

#include "../../Map/Actor.hpp"
#include "../../Base/Engine.hpp"
#include "Tiles.hpp"
#include "Tile.hpp"

#include <string>

class Player : public Actor
{
public:
  // default constructor
  Player() {}
  Player(std::string value, int x, int y, Color color, Engine *currentEngine);

  void update() override;
  void safeMove(int x, int y);

private:
  Engine *engine;
};
