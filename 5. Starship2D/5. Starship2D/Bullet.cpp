#include "Bullet.h"

Bullet::Bullet() : GameObject("shot1.png") {
	this->setScale(0.3f, 0.3f);
	this->isMoving = false;
}

void Bullet::setTexturePath(std::string txtrPath) {
	sf::Texture textr;

	if (!textr.loadFromFile(txtrPath))
	{
		std::cout << "Texture Not Found!" << std::endl;
	}

	this->setTexture(textr);
}