#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(float x, float y, float s, float w, float h)
{
	xPos = x;
	yPos = y;
	speed = s;
	velocity = sf::Vector2f(0.0f, 0.0f);
	acceleration = sf::Vector2f(0.0f, 0.0f);
	width = w;
	height = h;
}

void Player::setSpeed(float s) 
{
	speed = s;
}

void Player::applyForce(sf::Vector2f force) 
{
	acceleration += force;
}

void Player::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		applyForce(sf::Vector2f(-speed, 0.0f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		applyForce(sf::Vector2f(speed, 0.0f));
	}
}

void Player::update(float deltaTime)
{
	Input();
	velocity += acceleration * deltaTime;

	float maxSpeed = speed;
	if (velocity.x > maxSpeed)
		velocity.x = maxSpeed;
	else if (velocity.x < -maxSpeed)
		velocity.x = -maxSpeed;

	xPos = xPos + velocity.x * deltaTime;

	if (xPos >= sf::VideoMode::getDesktopMode().width) {
		xPos = sf::VideoMode::getDesktopMode().width;
	}
	else if (xPos < 0) {
		xPos = 0;
	}

	acceleration = sf::Vector2f(0.0f, 0.0f);
}

void Player::draw(sf::RenderWindow* window)
{
	sf::CircleShape triangle(width, height);
	triangle.setPosition(xPos, yPos);
	window->draw(triangle);
}