#include "Player.h"

Player::Player() : Starship("ship1.png"){
	bullets[this->currentBullet].setPosition(getPosition().x + 30, getPosition().y + 30);
	bullets[this->currentBullet].setScale(0.3f, 0.3f);
}
