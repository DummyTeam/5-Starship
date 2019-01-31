#include "Game.h"
#include "DataProvider.h"

Game::Game() {
	enemies.resize(DP::numberOfEnemies);
	enemies[0].velocity *= -1;

	for (size_t i = 0; i < 2; i++)
	{
		enemies[i].setPosition(DP::screenWidth - 80.f, ((i *  DP::screenHeight) / 2) + (DP::screenHeight / 4) - 30);
		enemies[i].healthBar.setPosition(DP::screenWidth - 80.f, ((i *  DP::screenHeight) / 2) + (DP::screenHeight / 4) - 30);
	}
}

void Game::start() {
	RenderWindow window(VideoMode(DP::screenWidth, DP::screenHeight), "Starship 2D");
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	int timeCounter = 0;
	int bulletCounter = 0;

	while (window.isOpen())
	{
		timeCounter++;

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

		bulletCounter = (timeCounter % 600) / 40;
		player.bullets[bulletCounter].isMoving = true;
		enemies[0].bullets[bulletCounter].isMoving = true;
		enemies[1].bullets[bulletCounter].isMoving = true;

		if ((timeCounter % 600) % 40 <= 1)
		{
			player.bullets[bulletCounter].setPosition(player.getPosition().x + 30, player.getPosition().y + 30);

			enemies[0].bullets[bulletCounter].setPosition(enemies[0].getPosition().x - 30, enemies[0].getPosition().y + 30);
			enemies[1].bullets[bulletCounter].setPosition(enemies[1].getPosition().x - 30, enemies[1].getPosition().y + 30);

			player.bullets[bulletCounter].setScale(0.3f, 0.3f);
			enemies[0].bullets[bulletCounter].setScale(0.3f, 0.3f);
			enemies[1].bullets[bulletCounter].setScale(0.3f, 0.3f);
		}

		for (int j = 0; j < 15; j++) {
			if (player.bullets[j].isMoving)
			{
				player.bullets[j].move(5.f, 0.f);

				if (player.bullets[j].getGlobalBounds().intersects(enemies[0].getGlobalBounds()))
				{
					player.bullets[j].isMoving = false;
					player.bullets[j].setScale(0.f, 0.f);
					enemies[0].healthBar.injured(10);

				}
				if (player.bullets[j].getGlobalBounds().intersects(enemies[1].getGlobalBounds()))
				{
					player.bullets[j].isMoving = false;
					player.bullets[j].setScale(0.f, 0.f);
					enemies[1].healthBar.injured(10);
				}
			}
		}

		for (size_t i = 0; i < 2; i++)
		{
			for (int j = 0; j < 15; j++) {
				if (enemies[i].bullets[j].isMoving)
				{
					enemies[i].bullets[j].move(-5.f, 0.f);

					if (player.getGlobalBounds().intersects(enemies[i].bullets[j].getGlobalBounds()))
					{
						enemies[i].bullets[j].isMoving = false;
						enemies[i].bullets[j].setScale(0.f, 0.f);
						player.healthBar.injured(10);
					}
				}
			}
		}

		for (size_t i = 0; i < 2; i++)
		{
			if (
				(enemies[i].getPosition().y > 0 &&
					enemies[i].getPosition().y < 290)
				||
				(enemies[i].getPosition().y > 310 &&
					enemies[i].getPosition().y < 550)
				) {
				enemies[i].move(0.f, enemies[i].velocity * 2.f);
				enemies[i].healthBar.move(0.f, enemies[i].velocity * 2.f);
			}
			else
			{
				enemies[i].velocity *= -1;
				enemies[i].move(0.f, enemies[i].velocity *  2.f);
				enemies[i].healthBar.move(0.f, enemies[i].velocity *  2.f);
			}
		}

		window.clear();

		window.draw(background);

		for (int i = 0; i < 2; i++)
		{
			window.draw(enemies[i]);
			window.draw(enemies[i].healthBar);
		}

		for (int j = 0; j < 15; j++) {
			if (player.bullets[j].isMoving)
			{
				window.draw(player.bullets[j]);
			}
		}

		for (size_t i = 0; i < 2; i++)
		{
			for (int j = 0; j < 15; j++) {
				if (enemies[i].bullets[j].isMoving)
				{
					window.draw(enemies[i].bullets[j]);
				}
			}
		}

		window.draw(player);
		window.draw(player.healthBar);

		window.display();

		timeCounter %= 600;
	}
}