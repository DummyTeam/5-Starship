#pragma once

#include "GameObject.h"
#include "HealthBar.h"

class Starship : public GameObject
{
public:
	Starship();
	~Starship();

private:
	HealthBar healthBar;
};
