#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Player.h"

using namespace std;

int main()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(500, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	sf::Clock clock;
	sf::Time deltaTime;

	Player* player = new Player(500, 450, 20, 3, 500, 3.0f);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}
			deltaTime = clock.restart();
			float deltaTimeInSeconds = deltaTime.asSeconds();
			player->update(deltaTimeInSeconds, window);
			
			window->clear(sf::Color(104, 104, 104));
			player->draw(window);
			window->display();
	};

	return 0;
}