#pragma once
#include "Shape.h"
#include <SFML\Graphics.hpp>

class Rectangle : public Shape {

public:
	Rectangle(float x, float y, float w, float h, sf::Color c);
	void draw(sf::RenderWindow* window);
};

