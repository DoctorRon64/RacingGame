#include "Car.h"
#include "Shape.h"
#include <SFML\Graphics.hpp>

Car::Car(float x, float y, float w, float h, float s, float f)
	: position(x,y), width(w), height(h), speed(s), friction(f), rb(position.x, position.y, speed, friction)
{
	texture.loadFromFile("textures/Car.png");
	sprite = sf::Sprite(texture);
	sprite.setScale(width, height);
}

float Car::clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

void Car::update(sf::RenderWindow* window, float deltaTime) 
{
	rb.Update(deltaTime);
	position = rb.getPosition();

	sf::Vector2u windowSize = window->getSize();
	const float leftBoundary = 0.0f;
	const float rightBoundary = windowSize.y - (sprite.getTexture()->getSize().y * sprite.getScale().y);

	position.y = clamp(position.y, leftBoundary, rightBoundary);
	sprite.setPosition(position);
	draw(window);
}

void Car::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}