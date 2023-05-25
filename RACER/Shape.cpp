#include "Shape.h"

Shape::Shape()
{
	width = 0;
	height = 0;
	alpha = 0.0;
}

Shape::Shape(int w, int h)
{
	width = w;
	height = h;
	alpha = 0.0;
}

void Shape::setAlpha(float a)
{
	alpha = a;
}

float Shape::area()
{
	return width * height;
}

void Shape::draw()
{
	
}

