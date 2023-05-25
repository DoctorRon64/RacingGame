#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	Rectangle Speler = Rectangle(100, 200);
	Speler.setAlpha(0.5);
	Speler.draw(window);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
			window->clear(sf::Color::Cyan);

			Speler.draw(window);
			window->display();
		}
	};

	return 0;
}