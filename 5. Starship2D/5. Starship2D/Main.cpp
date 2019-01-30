#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(800, 600), "Starship 2D");
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	Texture playerTexture;
	Texture enemyTexture;
	Texture backgroundTexture;

	if (!playerTexture.loadFromFile("ship1.png") || !enemyTexture.loadFromFile("ship2.png") || !backgroundTexture.loadFromFile("bck.png"))
	{
		std::cout << "Some textures are not found!" << std::endl;
		return 0;
	}

	playerTexture.setSmooth(true);
	enemyTexture.setSmooth(true);
	backgroundTexture.setSmooth(true);

	playerTexture.setRepeated(true);
	enemyTexture.setRepeated(true);
	backgroundTexture.setRepeated(true);

	Sprite player;
	Sprite enemy;
	Sprite background;

	player.setTexture(playerTexture);
	enemy.setTexture(enemyTexture);
	background.setTexture(backgroundTexture);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				player.move(0.f, -3.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player.move(0.f, 3.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player.move(-3.f, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player.move(3.f, 0.f);
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(background);
		window.draw(enemy);
		window.draw(player);
		window.display();
	}

	return 0;
}