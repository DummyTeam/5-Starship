#pragma once

#include <string>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite
{
public:

	GameObject();
	GameObject(std::string);

	void setVisible(bool);
	bool getVisible();
	void  setObjectTexture(std::string);

	std::string txtrPath = "ship1.png";

private:
	bool isVisible;
	sf::Texture texture;
};
