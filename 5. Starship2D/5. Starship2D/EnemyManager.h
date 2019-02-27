#pragma once

#include "Enemy.h"
#include "Player.h"
#include <vector>
using namespace sf;

class EnemyManager
{
public:
	EnemyManager();
	std::vector<Starship> enemies;
	void animateEnemies(Player&);
	void positionEnemiesInit();
	void shoot(int);
};
