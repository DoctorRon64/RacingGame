#include "RigidBody.h"
#include <SFML/Graphics.hpp>

RigidBody::RigidBody(float x, float y, float s, float f)
{
	position = sf::Vector2f(x, y);  
	speed = s;
	friction = f;
	gravity = 9.81f;
	velocity = sf::Vector2f(0.0f, 0.0f);
	acceleration.y = speed;
}

void RigidBody::Update(float deltaTime)
{
	velocity = sf::Vector2f(0, speed);
	acceleration = sf::Vector2f(0, -gravity);

	//v - friction * v * t
	velocity.y -= friction * velocity.y * deltaTime;

	//v = a * t
	velocity += acceleration * deltaTime;
	//s = v * t
	position += velocity * deltaTime;
}

sf::Vector2f RigidBody::getPosition()
{
	return position;
}