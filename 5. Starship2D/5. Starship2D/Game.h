#pragma once

#include "EnemyManager.h"
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
	void handleEvents(RenderWindow&);

	Player player;
	EnemyManager enemyManager;
	Background background;

};