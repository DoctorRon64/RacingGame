#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class Circle : public Shape {

private:
	float radius;

public:
	void radiusResize(float r);
	void draw(sf::RenderWindow* window);
	Circle(float x, float y, float r, sf::Color c);
};