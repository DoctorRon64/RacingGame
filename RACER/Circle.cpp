#include "Circle.h"
#include <SFML/Graphics.hpp>

Circle::Circle(float x, float y, float r, sf::Color c)
{
	xPos = x;
	yPos = y;
	radius = r;
	colorShape = c;
}

void Circle::radiusResize(float r) 
{
	radius = r;
}

void Circle::draw(sf::RenderWindow* window)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(colorShape);
	circle.setPosition(xPos, yPos);
	window->draw(circle);
}