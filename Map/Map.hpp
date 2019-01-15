#pragma once

#include "Layer.hpp"

class Map {
public:

    // default constructor
    Map();

    std::vector<Layer*> getLayers() { return layers; }

    // add a new Layer to the layers vector
    void addLayer(Layer* layer);
    // update each layer
    void update();

private:
    std::vector<Layer*> layers;

};
