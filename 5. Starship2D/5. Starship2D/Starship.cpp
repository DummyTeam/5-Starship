#include "Starship.h"
#include "DataProvider.h"

Starship::Starship() {
	Starship("ship1.png");
}

Starship::Starship(std::string txtrPath) :GameObject(txtrPath) {
	setScale(0.5f, 0.5f);
	bullets.resize(DP::numberOfBullets);
}
