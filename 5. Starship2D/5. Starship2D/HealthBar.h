#pragma once

#include "GameObject.h"

class HealthBar : public GameObject
{
public:
	HealthBar();
	void rescale();
	void injured(int);

	void setHealth(int);
	int health;
};
