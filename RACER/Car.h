#pragma once
#include <SFML\Graphics.hpp>

class Car
{
private:
	sf::Vector2f position;
	float width, height;

public:
	Car(float x, float y, float w, float h);
	void draw(sf::RenderWindow* window);
};

