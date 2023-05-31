#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Shape.h"
#include "Player.h"
#include "Car.h"

using namespace std;

int main()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	sf::Clock clock;
	sf::Time deltaTime;

	Player player = Player(500, 450, 20, 3, 1000, 3.0f);
	Car EnemieCar = Car(10, 10, 200, 200);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}

		deltaTime = clock.restart();
		float deltaTimeInSeconds = deltaTime.asSeconds();
		player.update(deltaTimeInSeconds, window);
		player.draw(window);
		EnemieCar.draw(window);
		
		window->clear(sf::Color(104, 104, 104));
		window->display();
	};

	return 0;
}