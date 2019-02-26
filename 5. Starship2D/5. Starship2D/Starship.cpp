#include "Starship.h"
#include "DataProvider.h"

Starship::Starship() {
	Starship("ship1.png");
	currentBullet = 0;
	bullets.resize(DP::numberOfBullets);
	bullets[currentBullet].isMoving = true;
}

Starship::Starship(std::string txtrPath) :GameObject(txtrPath) {
	this->velocity = 2.0;
	setScale(0.5f, 0.5f);
}

void Starship::shoot(int timeCounter) {
	currentBullet = (timeCounter % 600) / 40;
	bullets[currentBullet].setPosition(getPosition().x - 30, getPosition().y + 30);
	bullets[currentBullet].setScale(0.3f, 0.3f);
}

void Starship::animateBullets(Starship& obstacle) {
	for (int j = 0; j < 15; j++) {
		if (bullets[j].isMoving)
		{
			bullets[j].move(-5.f, 0.f);
			if (obstacle.getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
			{
				bullets[j].isMoving = false;
				bullets[j].setScale(0.f, 0.f);
				obstacle.healthBar.injured(10);
			}
		}
	}
}

void Starship::animateBullets(std::vector<Starship>& obstacles) {
	for (int j = 0; j < 15; j++) {
		if (bullets[j].isMoving)
		{
			bullets[j].move(-5.f, 0.f);
			for (size_t i = 0; i < obstacles.size(); i++)
			{
				if (obstacles[i].getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
				{
					bullets[j].isMoving = false;
					bullets[j].setScale(0.f, 0.f);
					obstacles[i].healthBar.injured(10);
				}
			}
		}
	}
}