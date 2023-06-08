#include "Car.h"
#include <SFML/Graphics.hpp>

Car::Car(float x, float y, float w, float h, float s, float f, float Carmass, sf::Sprite spriteRef, sf::RenderWindow* winD)
	: position(x, y), width(w), height(h), speed(s), friction(f), sprite(spriteRef), window(winD)
{
	sprite.setScale(width, height);
}

void Car::update(float deltaTime)
{
	rb.Update(deltaTime);
	position = rb.getPosition();

	sprite.setPosition(position.ToSFMLVector2());
	DrawCar();
}

v2P::Vector2 Car::getPosition()
{
	return v2P::Vector2(position);
}

bool Car::CheckIfDeath(float sH)
{
	float boundary = sH + sprite.getGlobalBounds().height;
	if (position.y >= boundary)
	{
		return true;
	}
	return false;
}

void Car::DrawCar()
{
	window->draw(sprite);
}

float Car::getCarWidth()
{
	float width = sprite.getGlobalBounds().width;
	return width;
}

float Car::getCarHeight()
{
	float height = sprite.getGlobalBounds().height;
	return height;
}
