#include "Car.h"
#include "Shape.h"
#include <SFML\Graphics.hpp>

Car::Car(float x, float y, float w, float h, float m, float f)
	: position(x,y), width(w), height(h), mass(m), friction(f)
{
	texture.loadFromFile("textures/Car.png");
	sprite = sf::Sprite(texture);
	sprite.setScale(width, height);
}

void Car::draw(sf::RenderWindow* window, float deltaTime)
{
	position.x = 0.5 * 9.81 * deltaTime;
	sprite.setPosition(position);
	window->draw(sprite);
}