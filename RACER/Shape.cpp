#include "Shape.h"
#include <SFML/Graphics.hpp>

Shape::Shape(float x, float y, float w, float h, sf::Color c)
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;
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

void Shape::draw()
{
	
}

