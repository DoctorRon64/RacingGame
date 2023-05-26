#pragma once
#include <SFML/Graphics.hpp>

class Shape {

protected:
	float width, height;
	float xPos, yPos;
	sf::Color colorShape;

public:
	Shape() = default;
	Shape(float x, float y, float w, float h, sf::Color c);
	virtual void setPosition(float x, float y);
	virtual void Resize(float w, float h);
	virtual void draw();
};

