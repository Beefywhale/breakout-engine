#include "../Base/Engine.hpp"
#include <SDL2/SDL.h>
#include <iostream>

// main function
int main() {

    // create an Engine object to process input and rendering.
    Engine engine = Engine("Title", 640, 480);


    // game loop
    while (engine.isRunning()) {
        engine.draw();
    }
    return 0;
}
