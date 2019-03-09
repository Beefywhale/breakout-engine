#include "CustomMap.hpp"

CustomMap::CustomMap() : Map()
{
}

void CustomMap::load(std::string path)
{
    json j;
    std::ifstream(path) >> j;

    data = j;

    for (auto &layer : data["layers"])
    {
        addLayer(layer["name"].get<std::string>(), new Layer());
    }
    for (auto &actor : data["actors"])
    {
        int x = actor["x"].get<int>();
        int y = actor["y"].get<int>();

        std::string value = actor["value"].get<std::string>();

        Color color = Color(actor["color"][0].get<int>(), actor["color"][1].get<int>(), actor["color"][2].get<int>());
        std::string layer = actor["layer"].get<std::string>().c_str();
        std::string type = actor["type"].get<std::string>();

        // define what types to create.
        if (type == std::string("door"))
        {
            bool solid = actor["solid"].get<bool>();
            getLayers()[layer]->addActor(new Door(value, x, y, color, solid));
        }
        else
        {
            bool solid = actor["solid"].get<bool>();
            getLayers()[layer]->addActor(new Tile(value, x, y, color, solid));
        }
    }
}