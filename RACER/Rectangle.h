#pragma once
#include "Shape.h"
#include <SFML\Graphics.hpp>

class Rectangle : public Shape {

public:
	Rectangle(float x, float y, int w, int h, int line, float a);
	void draw(sf::RenderWindow* window);
};

