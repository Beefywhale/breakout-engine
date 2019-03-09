#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Window
{
public:
  // default constructor
  Window() {}

  // default destructor
  ~Window() { destroy(); }

  // constructor which handles title, width, and height parameters
  Window(std::string title, int width, int height);

  void destroy();
  void draw();
  void setRunning(bool run);

  SDL_Renderer *getRenderer() { return render; }
  bool isRunning() { return running; }

private:
  void init();
  void createWindow(std::string title, int width, int height);
  void createRenderer();

  bool running = true;
  SDL_Window *window;
  SDL_Renderer *render;
};