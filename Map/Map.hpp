#pragma once

#include <map>
#include <vector>
#include "Actor.hpp"
#include "../Base/Color.hpp"

class Map {
public:

    // default constructor
    Map();

    // get the Actors at a give x,y
    std::vector<Actor*> getActorsAt(int x, int y);
    // get all the current Actors in the Map
    std::map<std::pair<int, int>, std::vector<Actor*>> getActors() { return actors; }
    bool isActorAt(int x, int y);

    void addActor(Actor* actor);
    void update();

private:
    std::map<std::pair<int, int>, std::vector<Actor*>> actors;

};
