#include "Shape.h"

Shape::Shape(float x, float y, int w, int h, int line, float a) 
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	lineThickness = line;
	alpha = a;
}

void Shape::setPosition(int x, int y) 
{
	xPos = x;
	yPos = y;
}

void Shape::setAlpha(float a)
{
	alpha = a;
}

void Shape::setLineThickness(int lineT) 
{
	lineThickness = lineT;
}

void Shape::Resize(int w, int h)
{
	width = w;
	height = h;
}

float Shape::area()
{
	return width * height;
}

void Shape::draw()
{
	
}

