#pragma once

#include "Layer.hpp"

class Map
{
public:
  // default constructor
  Map();

  std::map<std::string, Layer *> getLayers() { return layers; }

  // add a new Layer to the layers vector
  void addLayer(std::string name, Layer *layer);
  // update each layer
  void update();

private:
  std::map<std::string, Layer *> layers;
};
