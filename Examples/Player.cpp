#include "Player.hpp"

void Player::update(const char* key) {
	std::string newKey = std::string(key);
	if (!newKey.empty()) {
		if (newKey == "W") {
			move(0, -1);
		} else if (newKey == "S") {
			move (0, 1);
		} if (newKey == "A") {
			move(-1, 0);
		} else if (newKey == "D") {
			move (1, 0);
		}
	}
}