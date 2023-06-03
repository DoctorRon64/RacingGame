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
	sf::Texture BackgroundImage;
	BackgroundImage.loadFromFile("textures/Background.png");
	sf::Sprite BgSprite(BackgroundImage);

	//delta time setup
	sf::Clock clock;
	sf::Time deltaTime;
	float deltaTimeInSeconds;

	//objects
	Player player = Player(500, 400, 0.12f, 0.12f, 2000, 4.0f);
	float randomValue = randomFloat(0, window->getSize().x);
	Car* car = new Car(randomValue, 10, 0.1f, 0.1f, 300, 4.0f);

	while (window->isOpen())
	{
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}

		window->clear(sf::Color().White);
		window->draw(BgSprite);

		deltaTime = clock.restart();
		deltaTimeInSeconds = deltaTime.asSeconds();
		player.update(deltaTimeInSeconds, window);

		if (car != nullptr && car->CheckIfDeath(window))
		{
			std::cout << "delete" << std::endl;
			delete car;
			car = nullptr;
		}
		else if (car != nullptr)
		{
			car->update(window, deltaTimeInSeconds);
			std::cout << "not delete" << std::endl;
		}
		

		window->display();
	};

	return 0;
}