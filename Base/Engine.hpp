#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <string>

#include "Window.hpp"
#include "Logger.hpp"
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
    void loadFont(char* path, int size);
    void destroy();
    
    // wrapper for Window's isRunning function
    bool isRunning() { return win->isRunning(); }
    bool isKeyDown(std::string name);
    Map* getMap() { return &currentMap; }
    Logger* getLogger() { return logger; }

private:
    Window* win;
    Logger* logger;
    TTF_Font* font;
    Map currentMap;
    std::vector<std::pair<int, int>> occupied;
    bool fontLoaded;
    std::map<std::string, bool> keysDown;
};
