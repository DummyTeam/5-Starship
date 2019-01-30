#pragma once

#include "GameObject.h"
#include "HealthBar.h"
#include "Gun.h"
#include <string>

class Starship : public GameObject
{
public:
	Starship();
	Starship(std::string);
	int health;
	HealthBar healthBar;
	Gun gun;

private:

};
