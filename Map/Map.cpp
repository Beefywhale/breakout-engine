#include "Map.hpp"

Map::Map() {}

void Map::addLayer(std::string name, Layer *layer)
{
    layers[name] = layer;
}

void Map::update()
{
    for (auto layer : layers)
    {
        layer.second->update();
    }
}