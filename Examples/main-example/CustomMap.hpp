#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "../../Map/Map.hpp"
#include "../../Base/Engine.hpp"
#include "Tile.hpp"
#include "Tiles.hpp"
#include "Player.hpp"

// include json parsing library
#include "libs/json.hpp"
using json = nlohmann::json;

class CustomMap : public Map
{
public:
  CustomMap();

  void load(std::string path);

  json getData() { return data; }

private:
  json data;
  Engine *engine;
};