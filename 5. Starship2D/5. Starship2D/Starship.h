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
	int health;
	HealthBar healthBar;
	std::vector<Bullet> bullets;

private:

};
