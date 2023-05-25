#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	Rectangle Player = Rectangle(100, 100, 100, 100, 2, 1);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
			window->clear(sf::Color::Cyan);

			Player.draw(window);
			window->display();
		}
	};

	return 0;
}