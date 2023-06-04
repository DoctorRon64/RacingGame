#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "WindowSetttings.h"
#include "GameManager.h"

using namespace std;

int main()
{
	//render window
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

	//Title & Icon
	WindowSetttings settings = WindowSetttings(window);

	//bg
	sf::Texture BackgroundImage;
	BackgroundImage.loadFromFile("textures/Background.png");
	sf::Sprite BgSprite(BackgroundImage);

	//delta time setup
	sf::Clock clock;
	sf::Time deltaTime;
	float deltaTimeInSeconds;

	//GameManager
	float screenWidth = window->getSize().x;
	GameManager gameManager = GameManager(window, screenWidth);

	//Update
	while (window->isOpen())
	{
		//Event
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}

		//window->clear(sf::Color().White);
		window->draw(BgSprite);

		deltaTime = clock.restart();
		deltaTimeInSeconds = deltaTime.asSeconds();

		//update
		gameManager.Update(window, deltaTimeInSeconds);

		window->display();
	};

	return 0;
}