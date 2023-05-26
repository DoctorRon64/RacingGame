#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	Rectangle Player = Rectangle(140, 100, 250, 100, sf::Color(226, 114, 0));
	Triangle Enemy = Triangle(700, 100, 100, 5, sf::Color::Green);
	Circle Item = Circle(200, 300, 40, sf::Color::Black);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
			window->clear(sf::Color(104,104,104));

			Player.draw(window);
			Item.draw(window);
			Enemy.draw(window);

			window->display();
		}
	};

	return 0;
}