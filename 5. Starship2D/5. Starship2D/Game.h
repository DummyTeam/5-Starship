#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Background.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;


class Game
{
public:
	Game();
	void start();

	Player player;
	std::vector<Enemy> enemies;
	Background background;

private:

};