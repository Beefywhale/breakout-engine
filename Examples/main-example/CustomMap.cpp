#include "CustomMap.hpp"

void CustomMap::load(std::string path)
{
    // load json from the given path into the data member
    json j;
    std::ifstream(path) >> j;
    data = j;

    // loop over the layers JSON array
    for (auto &layer : data["layers"])
    {
        // add that layer to the Map
        addLayer(layer["name"].get<std::string>(), new Layer());
    }
    // loop over all the objets in the "actors" JSON array
    for (auto &actor : data["actors"])
    {
        // get the expected data that each object in the "actors" array should contain and create a varaible for each
        int x = actor["x"].get<int>();
        int y = actor["y"].get<int>();
        std::string value = actor["value"].get<std::string>();
        std::string layer = actor["layer"].get<std::string>().c_str();
        std::string type = actor["type"].get<std::string>();
        Color color = Color(actor["color"][0].get<int>(), actor["color"][1].get<int>(), actor["color"][2].get<int>());

        // define what types to create

        // if the type is door add a Door object instead of a Tile
        if (type == std::string("door"))
        {
            // since the type is "door" the JSON data should have an entry for the solid bool
            // so we get it here
            bool solid = actor["solid"].get<bool>();

            // add a new Door object to the specified layer with the earlier defined variables.
            getLayers()[layer]->addActor(new Door(value, x, y, color, solid));
        }

        // if the type is anything not defined above then we assume it's just a Tile.
        else
        {
            // since the type is just a Tile the JSON data should have an entry for the solid bool
            // so we get it here
            bool solid = actor["solid"].get<bool>();

            // add a new Tile object to the specified layer with the earlier defined variables.
            getLayers()[layer]->addActor(new Tile(value, x, y, color, solid));
        }
    }
}