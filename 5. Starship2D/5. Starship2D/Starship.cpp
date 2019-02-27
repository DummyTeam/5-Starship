#include "Starship.h"
#include "DataProvider.h"

Starship::Starship() : GameObject("ship1.png") {
	std::cout << "Starship created" << std::endl;
	velocity = 2.0;
	bulletSpeed = 5.f;
	setScale(0.5f, 0.5f);
	currentBullet = 0;
	bullets.resize(DP::numberOfBullets);

}

void Starship::setBulletSpeed(float bulletSpeed) {
	this->bulletSpeed = bulletSpeed;
}

void Starship::shoot(int timeCounter) {
	currentBullet = (timeCounter % 600) / 40;
	bullets[currentBullet].isMoving = true;
	bullets[currentBullet].setPosition(getPosition().x - 30, getPosition().y + 30);
	bullets[currentBullet].setScale(0.3f, 0.3f);
}

void Starship::animateBullets(Starship& obstacle) {
	for (int j = 0; j < bullets.size(); j++) {
		if (this->bullets[j].isMoving)
		{
			this->bullets[j].move(bulletSpeed, 0.f);
			if (obstacle.getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
			{
				bullets[j].isMoving = false;
				bullets[j].setScale(0.f, 0.f);
				obstacle.damaged(10);
			}
		}
	}
}

void Starship::animateBullets(std::vector<Starship>& obstacles) {
	for (int j = 0; j < bullets.size(); j++) {
		if (this->bullets[j].isMoving)
		{
			this->bullets[j].move(bulletSpeed, 0.f);

			for (size_t i = 0; i < obstacles.size(); i++)
			{
				if (obstacles[i].getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
				{
					bullets[j].isMoving = false;
					bullets[j].setScale(0.f, 0.f);
					obstacles[i].damaged(10);
				}
			}
		}
	}
}

void Starship::damaged(float damage) {
	this->healthBar.injured(damage);
	if (this->healthBar.health <= 0)
	{
		this->destroyed();
	}
}

void Starship::destroyed() {
	this->bullets.clear();
	this->setVisible(false);
}

