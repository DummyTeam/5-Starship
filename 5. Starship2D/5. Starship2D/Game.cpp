#include "Game.h"
#include "DataProvider.h"

Game::Game() {
	this->enemyManager.positionEnemiesInit();
}

void Game::handleEvents(RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			&& (player.getPosition().y > 0)
			) {
			player.move(0.f, -10.f);
			player.healthBar.move(0.f, -10.f);
		}
		if (
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
				(player.getPosition().y < 550)
			) {
			player.move(0.f, 10.f);
			player.healthBar.move(0.f, 10.f);
		}
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Game::start() {

	// Creating window and configuring parameters
	RenderWindow window(VideoMode(DP::screenWidth, DP::screenHeight), "Starship 2D");
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	// Game counter - keeps track of the time
	int timeCounter = 0;

	while (window.isOpen())
	{
		// Keep track of the time
		timeCounter++;

		// Handle keyboard events
		handleEvents(window);

		// Every 2 seconds, shoot! Arbitrary numbers
		if ((timeCounter % 600) % 60 == 0)
		{
			player.shoot(timeCounter);
			enemyManager.shoot(timeCounter);
		}

		// Animating the bullets of enemies
		player.animateBullets(enemyManager.enemies);

		// Animating the enemies (Up and Down)
		enemyManager.animateEnemies(player);

		window.clear();

		// Draw background
		window.draw(background);

		// Draw enemies and thier bullets
		for (int i = 0; i < 2; i++)
		{
			window.draw(enemyManager.enemies[i]);
			window.draw(enemyManager.enemies[i].healthBar);
			for (int j = 0; j < 15; j++) {
				if (enemyManager.enemies[i].bullets[j].isMoving)
				{
					window.draw(enemyManager.enemies[i].bullets[j]);
				}
			}
		}

		// Draw player's bullets
		for (int j = 0; j < 15; j++) {
			if (player.bullets[j].isMoving)
			{
				window.draw(player.bullets[j]);
			}
		}

		// Draw player
		window.draw(player);

		// Draw player's healthbar
		window.draw(player.healthBar);

		window.display();

		// Limit the timeCounter
		timeCounter %= 600;
	}
}