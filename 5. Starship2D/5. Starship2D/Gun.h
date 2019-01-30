#pragma once

#include "Bullet.h"

class Gun
{
public:
	Gun();
	~Gun();

private:
	Bullet bullets[];
};
