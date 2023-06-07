#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
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

    unsigned int screenWidth = window->getSize().x;
    unsigned int screenHeight = window->getSize().y;
    float screenWidthFloat = static_cast<float>(screenWidth);
    float screenHeightFloat = static_cast<float>(screenHeight);


    GameManager gameManager = GameManager(window, textureLibrary, screenWidthFloat, screenHeightFloat);

    // BackgroundSprites
    sf::Sprite BgSprite;
    sf::Sprite LoseSprite;
    sf::Sprite WinSprite;
    BgSprite.setTexture(textureLibrary->BgTexture);
    LoseSprite.setTexture(textureLibrary->LoseTexture);
    WinSprite.setTexture(textureLibrary->WinTexture);

    LoseSprite.setScale(screenWidthFloat / textureLibrary->LoseTexture.getSize().x, screenHeightFloat / textureLibrary->LoseTexture.getSize().y);
    WinSprite.setScale(screenWidthFloat / textureLibrary->WinTexture.getSize().x, screenHeightFloat / textureLibrary->WinTexture.getSize().y);

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
            window->draw(BgSprite);
            break;
        case 1:
            window->draw(LoseSprite);
            break;
        case 2:
            window->draw(WinSprite);
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