#include "Rectangle.h"
#include <SFML/Graphics.hpp>

Rectangle::Rectangle(float x, float y, float w, float h, sf::Color c)
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	colorShape = c;
}

void Rectangle::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Rectangle::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(colorShape);
	rectangle.setPosition(xPos, yPos);
	window->draw(rectangle);
}