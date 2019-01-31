#include "HealthBar.h"


HealthBar::HealthBar() : GameObject("rect.png") {
	this->setScale(0.3f, 0.1f);
	this->health = 100;
	this->setColor(sf::Color(0, 250, 0));
}

void HealthBar::rescale() {
	this->setScale(0.3f * (health / 100.0), 0.1f);
}

void HealthBar::injured(int damage) {
	this->setHealth(this->health - damage);
	rescale();
}

void HealthBar::setHealth(int health) {
	this->health = (health <= 0) ? 0 : health;
}

