#include "Player.h"

Player::Player() : Starship() {
	std::cout << "Player created" << std::endl;
}


bool Player::isDead() {
	return this->healthBar.health <= 0;
}