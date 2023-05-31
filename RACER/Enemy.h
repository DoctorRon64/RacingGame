#pragma once
#include <SFML\Graphics.hpp>

class Enemy
{
private:
	sf::Vector2f position;
	float width, height;

public:
	Enemy(float x, float y, float w, float h);
};

