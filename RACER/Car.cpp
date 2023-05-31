#include "Car.h"
#include "Shape.h"
#include <SFML\Graphics.hpp>

Car::Car(float x, float y, float w, float h)
	: position(x,y), width(w), height(h)
{

};

void Car::draw(sf::RenderWindow* window)
{
	Shape Rectangle = Shape(position.x, position.y, width, height, 0, sf::Color().Red);
	Rectangle.drawRect(window);
}