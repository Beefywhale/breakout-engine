#include "Map.hpp"

Map::Map() {}

void Map::addLayer(Layer* layer) {
	layers.push_back(layer);
}

void Map::update() {
	for (auto layer : layers) {
		layer->update();
	}

}