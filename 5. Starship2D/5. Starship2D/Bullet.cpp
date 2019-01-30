#include "Bullet.h"

Bullet::Bullet() : GameObject("shot1.png") {
	this->setScale(0.3f, 0.3f);
	this->isMoving = false;
}