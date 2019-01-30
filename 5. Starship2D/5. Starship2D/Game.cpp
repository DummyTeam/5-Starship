#include "Game.h"

Game::Game() {
	enemies.resize(4);
}

void Game::start() {
	RenderWindow window(VideoMode(800, 600), "Starship 2D");
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
			}
			if (
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
					(player.getPosition().y < 580)
				) {
				player.move(0.f, 10.f);
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		bulletCounter = (timeCounter % 600) / 40;
		player.gun.bullets[bulletCounter].isMoving = true;
		std::cout << timeCounter << std::endl;

		if ((timeCounter % 600) % 40 <= 1)
		{
			player.gun.bullets[bulletCounter].setPosition(player.getPosition().x + 30, player.getPosition().y + 30);
		}

		for (int j = 0; j < 15; j++) {
			if (player.gun.bullets[j].isMoving)
			{
				player.gun.bullets[j].move(5.f, 0.f);
			}
		}

		window.clear();

		window.draw(background);

		for (int i = 0; i < 4; i++)
		{
			window.draw(enemies[i]);
		}

		for (int j = 0; j < 15; j++) {
			if (player.gun.bullets[j].isMoving)
			{
				window.draw(player.gun.bullets[j]);
			}
		}

		window.draw(player);

		window.display();

		timeCounter %= 600;
	}
}