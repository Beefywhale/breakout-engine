#include "../Base/Engine.hpp"
#include "../Base/Color.hpp"
#include "../Map/Layer.hpp"
#include "../Map/Map.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

// example custom layers
class EntityLayer: public Layer { public: EntityLayer(): Layer() {} };
class TileLayer: public Layer { public: TileLayer(): Layer() {} };

// main function
int main() {
    // create our own map
    Map map = Map();
    // add example layers to the map
    map.addLayer(new TileLayer());
    map.addLayer(new EntityLayer());

    // filling tile layer map with very basic stuff
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map.getLayers().at(0)->addActor(new Tile("#", j, i, Color(255,255,0), false));
        }
        map.getLayers().at(0)->addActor(new Tile("#", 0, i, Color(255,255,0), false));
        map.getLayers().at(0)->addActor(new Tile("|", 10, i, Color(0,255,255), true));
    }
    
    // create an Engine object to process input and rendering.
    Engine engine = Engine("Title", 640, 480, map);
    // set font
    engine.loadFont("font.ttf", 16);
    Player player("@", 0, 0, Color(255,255,0), &engine);

    // game loop
    while (engine.isRunning()) {
        engine.draw();
    }
    return 0;
}
