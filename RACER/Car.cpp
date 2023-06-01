#include "Car.h"
#include "Shape.h"
#include <SFML\Graphics.hpp>

Car::Car(float x, float y, float w, float h)
	: position(x,y), width(w), height(h)
{
	texture.loadFromFile("textures/Car.png");
	sprite = sf::Sprite(texture);
	sprite.setScale(width, height);
};

void Car::draw(sf::RenderWindow* window)
{
	sprite.setPosition(position.x, position.y);
	window->draw(sprite);
}