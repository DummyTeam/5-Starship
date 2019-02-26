#pragma once

#include "GameObject.h"
#include "HealthBar.h"
#include "Bullet.h"
#include <string>

class Starship : public GameObject
{
public:
	Starship();
	Starship(std::string);
	HealthBar healthBar;
	std::vector<Bullet> bullets;
	int currentBullet;
	void shoot(int);
	void animateBullets(Starship&);
	void animateBullets(std::vector<Starship>&);
	double velocity;
};
