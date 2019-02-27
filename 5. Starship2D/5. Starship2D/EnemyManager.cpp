#include "EnemyManager.h"
#include "DataProvider.h"

EnemyManager::EnemyManager() {
	std::cout << "EnemyManager created" << std::endl;

	enemies.resize(DP::numberOfEnemies);

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].setBulletSpeed(-5.f);
		enemies[i].setObjectTexture("Ship3.png");
	}
}

void EnemyManager::animateEnemies(Player& player) {
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getVisible())
			enemies[i].animateBullets(player);
		
	}

	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getVisible())
			if (
				(enemies[i].getPosition().y > 0 &&
					enemies[i].getPosition().y < 290)
				||
				(enemies[i].getPosition().y > 310 &&
					enemies[i].getPosition().y < 550)
				) {
				enemies[i].move(0.f, enemies[i].velocity * 2.f);
				enemies[i].healthBar.move(0.f, enemies[i].velocity * 2.f);
			}
			else
			{
				enemies[i].velocity *= -1;
				enemies[i].move(0.f, enemies[i].velocity *  2.f);
				enemies[i].healthBar.move(0.f, enemies[i].velocity *  2.f);
			}
	}
}

void EnemyManager::positionEnemiesInit() {
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].setPosition(DP::screenWidth - 80.f, ((i *  DP::screenHeight) / enemies.size()) + 30);
		enemies[i].healthBar.setPosition(DP::screenWidth - 80.f, ((i *  DP::screenHeight) / enemies.size()) + 30);
	}
}

void EnemyManager::shoot(int timeCounter) {
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getVisible())
			enemies[i].shoot(timeCounter);
	}
}