#pragma once

#include "GameObject.h"
#include "HealthBar.h"
#include "Bullet.h"
#include <string>

class Starship : public GameObject
{
public:
	Starship();
	HealthBar healthBar;
	std::vector<Bullet> bullets;
	int currentBullet;
	float bulletSpeed;
	void shoot(int);
	void setBulletSpeed(float);
	void damaged(float);
	void destroyed();

	void animateBullets(Starship&);
	void checkCollisionWithBullet(Starship&, Bullet&);
	void animateBullets(std::vector<Starship>&);
	double velocity;
};
