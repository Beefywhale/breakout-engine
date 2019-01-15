#include "Map.hpp"

Map::Map() {
    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		addActor(new Actor("#", j, i, Color(255,255,0)));
    	}
    	addActor(new Actor("#", 0, i, Color(255,255,0)));
    }
}

void Map::addActor(Actor* newActor) {
    actors[std::make_pair(newActor->getPosition().x, newActor->getPosition().y)].push_back(newActor);
}

std::vector<Actor*> Map::getActorsAt(int x, int y) {
	if (actors.find(std::make_pair(x, y)) != actors.end()) {
		return actors[std::make_pair(x, y)];
	}
}

bool Map::isActorAt(int x, int y) {
	if (actors.find(std::make_pair(x, y)) != actors.end()) {
        return true;
    } else {
    	return false;
    }
}

void Map::update() {
	std::map<std::pair<int, int>, std::vector<Actor*>> tempActors;

	for (auto actor : actors) {
		for (auto actor2 : actor.second) {
			tempActors[std::make_pair(actor2->getPosition().x, actor2->getPosition().y)].push_back(actor2);
		}
	}
	actors = tempActors;
}