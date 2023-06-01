#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Car.h"

using namespace std;

float randomFloat(float min, float max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}

int main()
{
	//render window
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	//render icon and title
	sf::Image windowIcon;
	windowIcon.loadFromFile("textures/icon.png");
	window->setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());
	window->setTitle("SUPER ULTRA OMEGA ULTIMATE MEGA RACERRRRRRR!!!!!!!");

	//delta time setup
	sf::Clock clock;
	sf::Time deltaTime;
	float deltaTimeInSeconds;

	//objects
	Player player = Player(500, 400, 0.12f, 0.12f, 2000, 4.0f);
	float randomValue = randomFloat(0, window->getSize().x);
	Car car = Car(randomValue, 10, 0.1f, 0.1f, 300, 4.0f);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}

		window->clear(sf::Color(104, 104, 104));

		deltaTime = clock.restart();
		deltaTimeInSeconds = deltaTime.asSeconds();
		player.update(deltaTimeInSeconds, window);

		car.update(window, deltaTimeInSeconds);

		window->display();
	};

	return 0;
}