#include "HealthBar.h"


HealthBar::HealthBar() : GameObject("rect.png") {
	this->setScale(0.3f, 0.1f);
	this->setColor(sf::Color(0, 250,0));
}