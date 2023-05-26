#include "Triangle.h"
#include <SFML/Graphics.hpp>

Triangle::Triangle(float x, float y, float w, float h, sf::Color c)
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	colorShape = c;
}

void Triangle::draw(sf::RenderWindow* window)
{
	sf::CircleShape triangle(width, height);
	triangle.setFillColor(colorShape);
	triangle.setPosition(xPos, yPos);
	window->draw(triangle);
}
