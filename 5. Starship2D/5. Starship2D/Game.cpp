#include "Game.h"

Game::Game() {
	enemies.resize(2);
}

void Game::start() {
	RenderWindow window(VideoMode(800, 600), "Starship 2D");
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	int timeCounter = 0;
	int bulletCounter = 0;

	for (size_t i = 0; i < 2; i++)
	{
		enemies[i].setPosition(720.f, (i * 300) + 120);
	}

	enemies[0].dir = 1.0;
	enemies[1].dir = -2.0;

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
			}
			if (
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
					(player.getPosition().y < 550)
				) {
				player.move(0.f, 10.f);
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		bulletCounter = (timeCounter % 600) / 40;
		player.gun.bullets[bulletCounter].isMoving = true;
		enemies[0].gun.bullets[bulletCounter].isMoving = true;
		enemies[1].gun.bullets[bulletCounter].isMoving = true;

		if ((timeCounter % 600) % 40 <= 1)
		{
			player.gun.bullets[bulletCounter].setPosition(player.getPosition().x + 30, player.getPosition().y + 30);

			enemies[0].gun.bullets[bulletCounter].setPosition(enemies[0].getPosition().x - 30, enemies[0].getPosition().y + 30);
			enemies[1].gun.bullets[bulletCounter].setPosition(enemies[1].getPosition().x - 30, enemies[1].getPosition().y + 30);

			player.gun.bullets[bulletCounter].setScale(0.3f, 0.3f);
			enemies[0].gun.bullets[bulletCounter].setScale(0.3f, 0.3f);
			enemies[1].gun.bullets[bulletCounter].setScale(0.3f, 0.3f);


		}

		for (int j = 0; j < 15; j++) {
			if (player.gun.bullets[j].isMoving)
			{
				player.gun.bullets[j].move(5.f, 0.f);

				if (player.gun.bullets[j].getGlobalBounds().intersects(enemies[0].getGlobalBounds()) ||
					player.gun.bullets[j].getGlobalBounds().intersects(enemies[1].getGlobalBounds())
					)
				{
					player.gun.bullets[j].isMoving = false;
					player.gun.bullets[j].setScale(0.f, 0.f);
				}
			}
		}

		for (size_t i = 0; i < 2; i++)
		{
			for (int j = 0; j < 15; j++) {
				if (enemies[i].gun.bullets[j].isMoving)
				{
					enemies[i].gun.bullets[j].move(-5.f, 0.f);

					if (player.getGlobalBounds().intersects(enemies[i].gun.bullets[j].getGlobalBounds()))
					{
						enemies[i].gun.bullets[j].isMoving = false;
						enemies[i].gun.bullets[j].setScale(0.f, 0.f);
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
				enemies[i].move(0.f, enemies[i].dir * 2.f);
			}
			else
			{
				enemies[i].dir *= -1;
				enemies[i].move(0.f, enemies[i].dir *  2.f);
			}
		}

		window.clear();

		window.draw(background);

		for (int i = 0; i < 2; i++)
		{
			window.draw(enemies[i]);
		}

		for (int j = 0; j < 15; j++) {
			if (player.gun.bullets[j].isMoving)
			{
				window.draw(player.gun.bullets[j]);
			}
		}

		for (size_t i = 0; i < 2; i++)
		{
			for (int j = 0; j < 15; j++) {
				if (enemies[i].gun.bullets[j].isMoving)
				{
					window.draw(enemies[i].gun.bullets[j]);
				}
			}
		}

		window.draw(player);

		window.display();

		timeCounter %= 600;
	}
}