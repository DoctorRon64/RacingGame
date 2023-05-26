#pragma once
#include "Shape.h"
#include <SFML\Graphics.hpp>

class Triangle : public Shape
{
public:
	Triangle(float x, float y, float w, float h, sf::Color c);
	void draw(sf::RenderWindow* window);
};

