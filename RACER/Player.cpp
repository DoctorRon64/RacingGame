#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Player::Player(float x, float y, float w, float h, float s, float f)
	: position(x, y), width(w), height(h), speed(s), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), friction(f)
{
	
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
	else 
	{
		acceleration.x = 0.0f;
		velocity.x = 0.0f;
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

	//we hebben een maxSpeed waar we aan houden
	const float maxVelocity = speed;
	if (velocity.x > maxVelocity)
		velocity.x = maxVelocity;
	else if (velocity.x < -maxVelocity)
		velocity.x = -maxVelocity;

	//s = v * deltaTime afstand
	position += velocity * deltaTime;

	std::cout << velocity.x;
	std::cout << "velocity" << std::endl;
	std::cout << acceleration.x;
	std::cout << "acceleration" << std::endl;
	std::cout << position.x;
	std::cout << "position x" << std::endl;


	//ga niet uit de border
	sf::Vector2u windowSize = window->getSize();
	const float leftBoundary = 0.0f;
	const float rightBoundary = windowSize.x - width * 2;
	position.x = clamp(position.x, leftBoundary, rightBoundary);
}

void Player::setSpeed(float s) 
{
	speed = s;
}

void Player::draw(sf::RenderWindow* window)
{
	sf::CircleShape triangle(width, height);
	triangle.setPosition(position);
	window->draw(triangle);
}