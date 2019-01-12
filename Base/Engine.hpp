#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Window.hpp"
#include "../Map/Map.hpp"

class Engine {
public:

    // default constructor
    Engine();

    // default destructor
    ~Engine() { destroy(); }

    // create Engine with a given Window and Map
    Engine(Window* window, Map map);

    // create Engine and have it make a window based on given parameters
    Engine(char* title, int width, int height);

    void init();
    // draw loop. draws Tiles from currentMap
    void draw();
    void changeFont(char* path, int size);
    void destroy();

    // wrapper for Window's isRunning function
    bool isRunning() { return win->isRunning(); }
    Map* getMap() { return &currentMap; }

private:
    Window* win;
    TTF_Font* font;
    Map currentMap;
};