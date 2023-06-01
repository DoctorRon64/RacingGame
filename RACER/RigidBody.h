#pragma once
#include <SFML/Graphics.hpp>

class RigidBody
{
private:
	sf::Vector2f position;
	float speed;
	float friction;
	float gravity;
	float timeMax;
	sf::Vector2f velocity, acceleration;
	
public:
	RigidBody(float x, float y, float s, float f);
	void Update(float deltaTime);
	sf::Vector2f getPosition();
};