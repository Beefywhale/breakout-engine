#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

#include "Window.hpp"
#include "../Map/Map.hpp"
#include "../Map/Actor.hpp"

class Engine {
public:

    // default constructor
    Engine();

    // default destructor
    ~Engine() { destroy(); }

    // create Engine with a given Window and Map
    Engine(Window* window, Map map);

    // create Engine and have it make a window based on given parameters, and have it create a blank map
    Engine(char* title, int width, int height);

    // create Engine with a window created with the given parameters, and set the map
    Engine(char* title, int width, int height, Map map);

    void init();
    // draw loop. draws Tiles from currentMap
    void draw();
    void changeFont(char* path, int size);
    void destroy();
    void addEvent(std::function<void()> event);
    
    // wrapper for Window's isRunning function
    bool isRunning() { return win->isRunning(); }
    Map* getMap() { return &currentMap; }

private:
    Window* win;
    TTF_Font* font;
    Map currentMap;
    std::vector<std::pair<int, int>> occupied;
    std::queue<std::function<void()>> events;
};
