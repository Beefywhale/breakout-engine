#include "Engine.hpp"

Engine::Engine() {
    // create a default window if none is specified
    win = new Window("", 600, 800);
    currentMap = Map();
    init();
}

Engine::Engine(Window* window, Map map) {
    // set window as the passed window
    win = window;
    currentMap = map;
    init();
}

Engine::Engine(char* title, int width, int height) {
    win = new Window(title, width, height);
    currentMap = Map();
    init();
}

Engine::Engine(char* title, int width, int height, Map map) {
    win = new Window(title, width, height);
    currentMap = map;
    init();
}

void Engine::init() {
    // start sdl TTF
    TTF_Init();

    // define font close window if failure to load font
    try {
        font = TTF_OpenFont("font.ttf", 16);
    } catch (...) {
         win->setRunning(false);
    }
}

void Engine::draw() {
    // handle window events
    SDL_Event evnt;

    const char* key = "\0";
    while (SDL_PollEvent(&evnt)) {
        if (evnt.type == SDL_QUIT) {
            // make the window to stop running
            win->setRunning(false);
        } else if (evnt.type == SDL_KEYDOWN) {
            key = SDL_GetKeyName(evnt.key.keysym.sym);
        }
    }

    SDL_RenderClear(win->getRenderer());

    // render here

    // render all Actors in current map
    for (int i =  currentMap.getLayers().size(); i--;) {
        auto layer = currentMap.getLayers().at(i);
        for (auto actorM : layer->getActors()) {
            auto actor = actorM.second;
            if (std::find(occupied.begin(), occupied.end(), std::make_pair(actor->getPosition().x, actor->getPosition().y)) == occupied.end()) {

                occupied.push_back(std::make_pair(actor->getPosition().x, actor->getPosition().y));

                // set fonts color
                SDL_Color color = { actor->getColor().red, actor->getColor().green, actor->getColor().blue };

                // set surface to render to
                SDL_Surface* surface = TTF_RenderText_Solid(font, actor->getValue(), color);
                // create texture from surface
                SDL_Texture* texture = SDL_CreateTextureFromSurface(win->getRenderer(), surface);

                // render texture
                int width, height = 0;
                SDL_QueryTexture(texture, NULL, NULL, &width, &height);
                SDL_Rect textureRect = { actor->getPosition().x * (width+2),
                                         actor->getPosition().y * (height-2), width, height };
                SDL_RenderCopy(win->getRenderer(), texture, NULL, &textureRect);

                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
            actor->update(key);
        }
    }

    SDL_RenderPresent(win->getRenderer());
    key = "\0";
    currentMap.update();
    occupied.clear();
}

void Engine::changeFont(char* path, int size) {
    font = TTF_OpenFont(path, size);
}

void Engine::destroy() {
    TTF_CloseFont(font);
    TTF_Quit();
}
