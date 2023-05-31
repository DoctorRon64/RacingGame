#pragma once
#include <SFML/Graphics.hpp>

class Shape {

protected:
	float width, height;
	float radius;
	float xPos, yPos;
	sf::Color colorShape;

public:
	Shape(float x, float y, float w, float h, float r, sf::Color c);
	void setPosition(float x, float y);
	void Resize(float w, float h);
	void drawRect(sf::RenderWindow* window);
	void drawTri(sf::RenderWindow* window);
	void drawCirc(sf::RenderWindow* window);
};

