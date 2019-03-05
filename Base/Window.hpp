#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "iostream"

class Window
{
  public:
    // default constructor
    Window() {}

    // default destructor
    ~Window() { destroy(); }

    // constructor which handles title, width, and height parameters
    Window(char *title, int width, int height);

    void destroy();
    void draw();
    void setRunning(bool run);

    SDL_Renderer *getRenderer() { return render; }
    bool isRunning() { return running; }

  private:
    void init();
    void createWindow(char *title, int width, int height);
    void createRenderer();

    bool running = true;
    SDL_Window *window;
    SDL_Renderer *render;
};