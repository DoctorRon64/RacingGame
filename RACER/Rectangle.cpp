#include "Rectangle.h"
#include <SFML/Graphics.hpp>

Rectangle::Rectangle(float x, float y, int w, int h, int line,float a)
{
	
}	

void Rectangle::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOutlineThickness(lineThickness);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setPosition(xPos, yPos);

	window->draw(rectangle);
}