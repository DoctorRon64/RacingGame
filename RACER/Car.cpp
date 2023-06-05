#include "Car.h"
#include "Shape.h"
#include <SFML\Graphics.hpp>

Car::Car(float x, float y, float w, float h, float s, float f, sf::Sprite spriteRef)
	: position(x, y), width(w), height(h), speed(s), friction(f), rb(position.x, position.y, speed, friction), sprite(spriteRef)
{
	sprite.setScale(width, height);
}

void Car::update(sf::RenderWindow* window, float deltaTime) 
{
	rb.Update(deltaTime);
	position = rb.getPosition();
	sprite.setPosition(position);
	draw(window);
}

bool Car::CheckIfDeath(sf::RenderWindow* window)
{
	sf::Vector2u windowSize = window->getSize();
	const float boundary = windowSize.y + (sprite.getTexture()->getSize().y * sprite.getScale().y);
	if (position.y >= boundary)
	{
		return true;
	}
	return false;
}

void Car::draw(sf::RenderWindow* window) 
{
	window->draw(sprite);
}

float Car::getCarWidth() 
{
	float width = sprite.getTexture()->getSize().x * sprite.getScale().x;
	return width;
}

float Car::getCarHeight()
{
	float height = sprite.getTexture()->getSize().y * sprite.getScale().y;
	return height;
}