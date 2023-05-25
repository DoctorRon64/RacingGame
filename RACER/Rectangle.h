#pragma once
#include "Shape.h"
#include <SFML\Graphics.hpp>

class Rectangle : public Shape {

private:
	int width;
	int height;
	float alpha;

public:
	Rectangle();
	Rectangle(int w, int h);
	void draw(sf::RenderWindow* window);
};

