#include "Rectangle.h"
#include <SFML/Graphics.hpp>

Rectangle::Rectangle()
{
	width = 0;
	height = 0;
	alpha = 0.0;
}

Rectangle::Rectangle(int w, int h)
{
	width = w;
	height = h;
	alpha = 0.0;
}

void Rectangle::setAlpha(float a)
{
	alpha = a;
}

void Rectangle::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setPosition(100, 100);

	window->draw(rectangle);
}