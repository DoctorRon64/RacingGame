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

void Car::update(sf::RenderWindow* window, float deltaTime) 
{
	CheckIfDeath(window);
	rb.Update(deltaTime);
	position = rb.getPosition();
	sprite.setPosition(position);
	draw(window);
}

void Car::CheckIfDeath(sf::RenderWindow* window)
{
	sf::Vector2u windowSize = window->getSize();
	const float boundary = windowSize.y + (sprite.getTexture()->getSize().y * sprite.getScale().y);
	if (position.y >= boundary) 
	{
		delete this;
	}
}

void Car::draw(sf::RenderWindow* window) 
{
	window->draw(sprite);
}