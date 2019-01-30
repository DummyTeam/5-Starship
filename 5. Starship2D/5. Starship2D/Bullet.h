#pragma once

#include "GameObject.h"
#include <string>

class Bullet : public GameObject
{
public:
	Bullet();
	bool isMoving;

	void setTexturePath(std::string);
private:

};
