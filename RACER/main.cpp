#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "WindowSetttings.h"
#include "TextureLibrary.h"
#include "GameManager.h"

using namespace std;

int main()
{
    // Render window
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SFML", sf::Style::Close | sf::Style::Resize);

    // Title & Icon
    WindowSetttings settings = WindowSetttings(window);

    // Create Textures
    TextureLibrary* textureLibrary = new TextureLibrary();
    textureLibrary->LoadFromFile();
    textureLibrary->SetSprite();

    // Delta time setup
    sf::Clock clock;
    sf::Time deltaTime;
    float deltaTimeInSeconds;

    // GameManager
    int GameState = 0;

    float screenWidth = window->getSize().x;
    float screenHeight = window->getSize().y;
    GameManager gameManager = GameManager(window, textureLibrary, screenWidth, screenHeight);

    // BackgroundSprites
    sf::Texture BgTextures[3];
    sf::Sprite BgSprites[3];

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            BgTextures[0].loadFromFile("textures/Background.png");
            BgSprites[0].setTexture(BgTextures[0]);
            //BgSprites[0].setScale(screenWidth / BgTextures[0].getSize().x, screenHeight / BgTextures[0].getSize().y);
            break;
        case 1:
            BgTextures[1].loadFromFile("textures/Lose.png");
            BgSprites[1].setTexture(BgTextures[1]);
            BgSprites[1].setScale(screenWidth / BgTextures[1].getSize().x, screenHeight / BgTextures[1].getSize().y);
            break;
        case 2:
            BgTextures[2].loadFromFile("textures/Win.png");
            BgSprites[2].setTexture(BgTextures[2]);
            BgSprites[2].setScale(screenWidth / BgTextures[2].getSize().x, screenHeight / BgTextures[2].getSize().y);
            break;
        }
    }

    // Update
    while (window->isOpen())
    {
        // Event
        sf::Event evnt;
        while (window->pollEvent(evnt))
        {
            if (evnt.type == evnt.Closed) { window->close(); }
        }

        switch (GameState)
        {
        case 0:
            window->draw(BgSprites[0]);
            break;
        case 1:
            window->draw(BgSprites[1]);
            break;
        case 2:
            window->draw(BgSprites[2]);
            break;
        }

        deltaTime = clock.restart();
        deltaTimeInSeconds = deltaTime.asSeconds();

        // Update
        if (GameState == 0)
        {
            gameManager.Update(window, deltaTimeInSeconds);
            GameState = gameManager.GameState;
        }

        window->display();
    }

    return 0;
}