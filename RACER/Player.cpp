#include "Player.h"
#include "Shape.h"	
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Player::Player(float x, float y, float w, float h, float s, float f)
	: position(x, y), width(w), height(h), speed(s), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), friction(f)
{
	texture.loadFromFile("textures/PlayerCar.png");
	sprite = sf::Sprite(texture);
	sprite.setScale(width, height);
}

void Player::Input()
{
	//zetten we de versnelling juist afhankelijk van knop press
	acceleration = sf::Vector2f(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		acceleration.x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		acceleration.x = speed;
	}
}

float Player::clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

void Player::update(float deltaTime, sf::RenderWindow* window)
{
	Input();
	
	//adden we friction
	velocity.x -= friction * velocity.x * deltaTime;

	//v = a * deltaTime
	velocity += acceleration * deltaTime;

	//s = v * deltaTime afstand
	position += velocity * deltaTime;

	//ga niet uit de border
	sf::Vector2u windowSize = window->getSize();
	const float leftBoundary = 0.0f;
	const float rightBoundary = windowSize.x - (sprite.getTexture()->getSize().x * sprite.getScale().x);
	position.x = clamp(position.x, leftBoundary, rightBoundary);

	draw(window);
}

void Player::setSpeed(float s) 
{
	speed = s;
}

void Player::draw(sf::RenderWindow* window)
{
	sprite.setPosition(position.x, position.y);
	window->draw(sprite);
}