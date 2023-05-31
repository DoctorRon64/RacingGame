#include "Shape.h"
#include <SFML/Graphics.hpp>

Shape::Shape(float x, float y, float w, float h, float r, sf::Color c)
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	radius = r;
	colorShape = c;
}

void Shape::setPosition(float x, float y) 
{
	xPos = x;
	yPos = y;
}

void Shape::Resize(float w, float h)
{
	width = w;
	height = h;
}

void Shape::drawRect(sf::RenderWindow* window)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(colorShape);
	rectangle.setPosition(xPos, yPos);
	window->draw(rectangle);
}

void Shape::drawTri(sf::RenderWindow* window)
{
	sf::CircleShape triangle(width, height);
	triangle.setFillColor(colorShape);
	triangle.setPosition(xPos, yPos);
	window->draw(triangle);
}

void Shape::drawCirc(sf::RenderWindow* window)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(colorShape);
	circle.setPosition(xPos, yPos);
	window->draw(circle);
}