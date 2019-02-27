#include "GameObject.h"

GameObject::GameObject() {

	isVisible = true;

	if (!texture.loadFromFile(txtrPath))
	{
		std::cout << "Texture Not Found!" << std::endl;
	}

	this->setTexture(texture);
}

GameObject::GameObject(std::string txtrPath)
{
	setObjectTexture(txtrPath);
}

void GameObject::setVisible(bool isVisible) {
	this->isVisible = isVisible;
	isVisible ? this->setScale(1.f, 1.f) : this->setScale(0.f, 0.f);
}

void GameObject::setObjectTexture(std::string txtrPath) {
	isVisible = true;

	if (!texture.loadFromFile(txtrPath))
	{
		std::cout << "Texture Not Found!" << std::endl;
	}

	this->setTexture(texture);
}

bool GameObject::getVisible() {
	return this->isVisible;
}
