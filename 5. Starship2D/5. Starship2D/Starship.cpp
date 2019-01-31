#include "Starship.h"

Starship::Starship() {
	Starship("ship1.png");
}

Starship::Starship(std::string txtrPath) :GameObject(txtrPath) {
	health = 100;
	setScale(0.5f, 0.5f);
	bullets.resize(15);
}