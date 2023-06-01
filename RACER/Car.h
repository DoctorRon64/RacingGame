#pragma once
#include <SFML\Graphics.hpp>

class Car
{
private:
	sf::Vector2f forces;
	sf::Vector2f acceleration, velocity, position;
	sf::Texture texture;
	sf::Sprite sprite;
	float mass;
	float friction;
	float width, height;

public:
	Car(float x, float y, float w, float h, float m, float f);
	void draw(sf::RenderWindow* window, float deltaTime);
};

