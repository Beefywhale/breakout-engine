#include "Window.hpp"

void Window::init()
{
    // start SDL with everything enabled
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Window::createWindow(char *title, int width, int height)
{
    // create an SDL window.
    window = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN);

    // check if it successfully created that window
    if (!window)
    {
        std::cout << "Create Window failed!";
        destroy();
        running = false;
    }
}

void Window::createRenderer()
{
    // create an SDL renderer on the window. make it hardware accelerated and vsync enabled.
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // check if it successfully created the renderer
    if (!render)
    {
        std::cout << "Create Renderer failed!";
        destroy();
    }
}

Window::Window(char *title, int width, int height)
{
    init();
    createWindow(title, width, height);
    createRenderer();
}

void Window::destroy()
{
    // close out of all sdl/ttf stuff
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();
}

void Window::setRunning(bool run)
{
    running = run;
}
