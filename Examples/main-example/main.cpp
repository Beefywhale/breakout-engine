#include "../../Base/Engine.hpp"
#include "Player.hpp"
#include "CustomMap.hpp"

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

// main function
int main()
{
    // create our own map
    CustomMap map = CustomMap();
    map.load("test.json");

    // create an Engine object to process input and rendering.
    Engine engine = Engine("Title", 640, 480, map);

    // set font
    engine.loadFont("font.ttf", 16);
    Player player("@", 0, 0, Color(255, 255, 0), &engine);
    map.getLayers()["player"]->addActor(&player);

    // game loop
    while (engine.isRunning())
    {
        engine.draw();
    }
    return 0;
}
