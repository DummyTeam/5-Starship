#pragma once

#include "Bullet.h"
#include <vector>

class Gun : public GameObject
{
public:
	std::vector<Bullet> bullets;

private:
};
