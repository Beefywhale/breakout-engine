#include "../../Base/Engine.hpp"
#include "Player.hpp"
#include "CustomMap.hpp"

#include <SDL2/SDL.h>
#include <string>

// main function
int main()
{
    // create our own CustomMap
    CustomMap map = CustomMap();
    // load map data from the test.json file
    map.load("test.json");

    // create a new Engine object with a title, width, height, and a Map
    Engine engine = Engine("My Title Here", 640, 480, map);

    // set engine font to render text with (will be replaced with images later)
    engine.loadFont("font.ttf", 16);

    // create a new Player object and add it to the map (only temporary until the map can do this automatically)
    Player player("@", 0, 0, Color(255, 255, 0), &engine);
    map.getLayers()["player"]->addActor(&player);

    // game loop
    while (engine.isRunning())
    {
        // process a new frame every loop
        engine.draw();
    }
    return 0;
}
