#include "../Base/Engine.hpp"
#include "../Base/Color.hpp"
#include "Player.hpp"
#include <SDL2/SDL.h>

// main function
int main() {

    // create an Engine object to process input and rendering.
    Engine engine = Engine("Title", 640, 480);
    Player player("@", 0, 0, Color(255,255,0), engine.getMap());
    //engine.getMap()->addActor(&player);

    // game loop
    while (engine.isRunning()) {
        engine.draw();
    }
    return 0;
}
