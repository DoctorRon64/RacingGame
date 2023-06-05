#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "WindowSetttings.h"
#include "TextureLibrary.h"
#include "GameManager.h"

using namespace std;

int main()
{
	//render window
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SFML", sf::Style::Close | sf::Style::Resize);

	//Title & Icon
	WindowSetttings settings = WindowSetttings(window);

	//CreateTextures
	TextureLibrary* textureLibrary = new TextureLibrary();
	textureLibrary->LoadFromFile();
	textureLibrary->SetSprite();

	//delta time setup
	sf::Clock clock;
	sf::Time deltaTime;
	float deltaTimeInSeconds;

	//GameManager
	int GameState = 0;

	float screenWidth = window->getSize().x;
	float screenHeight = window->getSize().y;
	GameManager gameManager = GameManager(window, textureLibrary, screenWidth, screenHeight);
		
	//BackgroundSprites
	sf::Texture *BgTextures[3];
	*BgTextures = new sf::Texture[3];
	sf::Sprite* BgSprites[3];
	*BgSprites = new sf::Sprite[3];

	for (int i = 0; i < sizeof(*BgTextures); i++)
	{
		switch (i)
		{
		case 0:
			BgTextures[0]->loadFromFile("textures/Background.png");
			BgSprites[0] = new sf::Sprite(*BgTextures[0]);
			BgSprites[0]->setScale(screenWidth, screenHeight);
			break;
		case 1:
			BgTextures[1]->loadFromFile("textures/Lose.png");
			BgSprites[1] = new sf::Sprite(*BgTextures[1]);
			BgSprites[1]->setScale(screenWidth, screenHeight);
			break;
		case 2:
			BgTextures[2]->loadFromFile("textures/Win.png");
			BgSprites[2] = new sf::Sprite(*BgTextures[2]);
			BgSprites[2]->setScale(screenWidth, screenHeight);
			break;
		}
	}

	//Update
	while (window->isOpen())
	{
		//Event
		sf::Event evnt;
		while(window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed) { window->close(); }
		}

		std::cout << GameState << std::endl;
		switch (GameState)
		{
		case 0:
			window->draw(*BgSprites[0]);
			break;
		case 1:
			window->draw(*BgSprites[1]);
			break;
		case 2:
			window->draw(*BgSprites[2]);
			break;
		}

		deltaTime = clock.restart();
		deltaTimeInSeconds = deltaTime.asSeconds();

		//update
		if (GameState == 0)
		{
			gameManager.Update(window, deltaTimeInSeconds);
			GameState = gameManager.GameState;
		}

		window->display();
	};

	return 0;
}