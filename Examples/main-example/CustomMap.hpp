#pragma once
#include <fstream>
#include <string>

#include "../../Map/Map.hpp"
#include "Tile.hpp"
#include "Tiles.hpp"
#include "Player.hpp"

// include json parsing library
#include "libs/json.hpp"
using json = nlohmann::json;

class CustomMap : public Map
{
public:
  CustomMap() : Map() {}

  void load(std::string path);

  json getData() { return data; }

private:
  json data;
};