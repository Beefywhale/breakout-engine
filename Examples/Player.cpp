#include "Player.hpp"

void Player::update(const char* key) {
	std::string newKey = std::string(key);
	if (!newKey.empty()) {
		if (newKey == "W") {
			safeMove(0, -1);
		} else if (newKey == "S") {
			safeMove(0, 1);
		} if (newKey == "A") {
			safeMove(-1, 0);
		} else if (newKey == "D") {
			safeMove(1, 0);
		}
	}
}

void Player::safeMove(int x, int y) {
	if (currentMap->isActorAt(position.x + x, position.y + y)) {
		move(x, y);
	}
}