#include "EnemyManager.h"
#include "DataProvider.h"

EnemyManager::EnemyManager() {
	enemies.resize(DP::numberOfEnemies);

}

void EnemyManager::animateEnemies(Player& player) {
	for (size_t i = 0; i < 2; i++)
	{
		enemies[i].animateBullets(player);
	}

	for (size_t i = 0; i < 2; i++)
	{
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
	for (size_t i = 0; i < DP::numberOfEnemies; i++)
	{
		enemies[i].setPosition(DP::screenWidth - 80.f, ((i *  DP::screenHeight) / DP::numberOfEnemies) + 30);
		enemies[i].healthBar.setPosition(DP::screenWidth - 80.f, ((i *  DP::screenHeight) / DP::numberOfEnemies) + 30);
	}
}

void EnemyManager::shoot(int timeCounter) {
	for (size_t i = 0; i < DP::numberOfEnemies; i++)
	{
		enemies[i].shoot(timeCounter);
	}
}