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

	Player player = Player(500, 400, 0.12f, 0.12f, 2000, 3.0f);
	Car car = Car(100, 20, 0.1f, 0.1f);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}
		window->clear(sf::Color(104, 104, 104));
		deltaTime = clock.restart();
		float deltaTimeInSeconds = deltaTime.asSeconds();

		player.update(deltaTimeInSeconds, window);
		car.draw(window);

		window->display();
	};

	return 0;
}