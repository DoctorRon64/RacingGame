#pragma once
#include <SFML\Graphics.hpp>

class Car
{
private:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	float width, height;

public:
	Car(float x, float y, float w, float h);
	void draw(sf::RenderWindow* window);
};

