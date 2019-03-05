#include "Engine.hpp"

Engine::Engine()
{
    // create a default window if none is specified
    win = new Window("", 600, 800);
    currentMap = Map();
    init();
}

Engine::Engine(Window *window, Map map)
{
    // set window as the passed window
    win = window;
    currentMap = map;
    init();
}

Engine::Engine(char *title, int width, int height)
{
    win = new Window(title, width, height);
    currentMap = Map();
    init();
}

Engine::Engine(char *title, int width, int height, Map map)
{
    win = new Window(title, width, height);
    currentMap = map;
    init();
}

void Engine::init()
{
    // start sdl TTF
    TTF_Init();

    fontLoaded = false;

    // define logger
    logger = new Logger();

    // set the keysDown map to be all false, as no keys are down at this moment.
    for (auto i : keysDown)
    {
        keysDown[i.first] = false;
    }
}

void Engine::draw()
{
    if (fontLoaded)
    {
        // handle window events
        SDL_Event evnt;

        while (SDL_PollEvent(&evnt))
        {
            if (evnt.type == SDL_QUIT)
            {
                // make the window to stop running
                win->setRunning(false);
            }
            else if (evnt.type == SDL_KEYDOWN)
            {
                keysDown[SDL_GetKeyName(evnt.key.keysym.sym)] = true;
            }
        }

        SDL_RenderClear(win->getRenderer());

        // render here

        // render all Actors in current map
        for (int i = currentMap.getLayers().size(); i--;)
        {
            auto layer = currentMap.getLayers().at(i);
            for (auto actorM : layer->getActors())
            {
                auto actor = actorM.second;
                if (std::find(occupied.begin(), occupied.end(), std::make_pair(actor->getPosition().x, actor->getPosition().y)) == occupied.end())
                {

                    occupied.push_back(std::make_pair(actor->getPosition().x, actor->getPosition().y));

                    // set fonts color
                    SDL_Color color = {actor->getColor().red, actor->getColor().green, actor->getColor().blue};

                    // set surface to render to
                    SDL_Surface *surface = TTF_RenderText_Solid(font, actor->getValue(), color);
                    // create texture from surface
                    SDL_Texture *texture = SDL_CreateTextureFromSurface(win->getRenderer(), surface);

                    // render texture
                    int width, height = 0;
                    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
                    SDL_Rect textureRect = {actor->getPosition().x * (width + 2),
                                            actor->getPosition().y * (height - 2), width, height};
                    SDL_RenderCopy(win->getRenderer(), texture, NULL, &textureRect);

                    SDL_DestroyTexture(texture);
                    SDL_FreeSurface(surface);
                }
                actor->update();
            }
        }

        SDL_RenderPresent(win->getRenderer());
        currentMap.update();
        occupied.clear();

        // reset keysDown map
        for (auto i : keysDown)
        {
            keysDown[i.first] = false;
        }
    }
    else
    {
        logger->error("No font loaded!");
        win->setRunning(false);
    }
}

void Engine::loadFont(char *path, int size)
{
    if (std::ifstream(path))
    {
        font = TTF_OpenFont(path, size);
        fontLoaded = true;
    }
    else
    {
        logger->error("Could not load font from path.");
        win->setRunning(false);
    }
}

void Engine::destroy()
{
    TTF_CloseFont(font);
    TTF_Quit();
}

bool Engine::isKeyDown(std::string name)
{
    if (keysDown.find(name) != keysDown.end())
    {
        return keysDown[name];
    }
}
