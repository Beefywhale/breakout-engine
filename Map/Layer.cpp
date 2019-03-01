#include "Layer.hpp"

Actor* Layer::getActorAt(int x, int y) {
    if (actors.find(std::make_pair(x, y)) != actors.end()) {
        return actors[std::make_pair(x, y)];
    }
}

bool Layer::isActorAt(int x, int y) {
    if (actors.find(std::make_pair(x, y)) != actors.end()) {
        return true;
    } else {
        return false;
    }
}

void Layer::update() {
    std::map<std::pair<int, int>, Actor*> tempActors;
    for (auto actorTemp : actors) {
	auto actorM = actorTemp.second;
        tempActors[std::make_pair(actorM->getPosition().x, actorM->getPosition().y)] = actorM;
    }
    actors.clear();
    actors = tempActors;
}

void Layer::addActor(Actor* actor) {
    actors[std::make_pair(actor->getPosition().x, actor->getPosition().y)] = actor;
}
