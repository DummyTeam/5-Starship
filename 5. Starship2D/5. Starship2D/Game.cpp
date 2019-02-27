#include "Game.h"
#include "DataProvider.h"

Game::Game() {
	std::cout << "Game created" << std::endl;
	this->enemyManager.positionEnemiesInit();
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
		// Check for win
		if (enemyManager.enemies.size() <= 0) {
			win(window);
			return;
		}

		// Check for game-over
		if (player.healthBar.health <= 0) {
			gameOver(window);
			return;
		}

		// Handle keyboard events
		handleEvents(window);

		// Every 2 seconds, shoot! Arbitrary numbers
		if ((timeCounter % 600) % 40 == 0)
		{
			player.shoot(timeCounter);
			enemyManager.shoot(timeCounter);
		}

		// Animating the bullets of player
		player.animateBullets(enemyManager.enemies);

		// Animating the enemies (Up and Down)
		enemyManager.animateEnemies(player);

		window.clear();

		// Draw background
		window.draw(background);

		// Draw enemies and thier bullets
		for (int i = 0; i < enemyManager.enemies.size(); i++)
		{
			window.draw(enemyManager.enemies[i]);
			window.draw(enemyManager.enemies[i].healthBar);
			for (int j = 0; j < enemyManager.enemies[i].bullets.size(); j++) {
				if (enemyManager.enemies[i].bullets[j].isMoving)
				{
					window.draw(enemyManager.enemies[i].bullets[j]);
				}
			}
		}

		// Draw player's bullets
		for (int j = 0; j < player.bullets.size(); j++) {
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

		// Keep track of the time
		timeCounter++;

		// Limit the timeCounter
		timeCounter %= 600;
	}
}

void Game::win(RenderWindow& window) {

}

void Game::gameOver(RenderWindow& window) {

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