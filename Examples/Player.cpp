#include "Player.hpp"

void Player::update() {
    if (engine->isKeyDown("W")) {
        safeMove(0, -1);
    } else if (engine->isKeyDown("S")) {
        safeMove(0, 1);
    } if (engine->isKeyDown("A")) {
        safeMove(-1, 0);
    } else if (engine->isKeyDown("D")) {
        safeMove(1, 0);
    }
}

void Player::safeMove(int x, int y) {
	if (engine->getMap()->getLayers().at(0)->isActorAt(position.x + x, position.y + y)) {
    	auto tileTemp = engine->getMap()->getLayers().at(0)->getActorAt(position.x + x, position.y + y);
		auto tile = static_cast<Tile*>(tileTemp);
		if (!tile->isSolid()) {
		    move(x, y);
		} else {
			// on collide with tile
	        engine->getLogger()->info("Player collided with a Tile at: " + std::to_string(tile->getPosition().x) + "," + std::to_string(tile->getPosition().y));

	        // do stuff when a tile is a door.
			if (!strcmp(tile->getType(),"door")) {
				auto door = static_cast<Door*>(tile);
				door->setSolid(false);
				door->setValue("=");
			}
	    }
    }
}
