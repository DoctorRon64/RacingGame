#include <SFML/Graphics.hpp>
#include "TextureLibrary.h"
#include "GameManager.h"
#include <memory>

int main()
{
    // Render window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 500), "SUPER ULTRA OMEGA ULTIMATE MEGA RACERRRRRRR!!!!!!!", sf::Style::Close | sf::Style::Resize);

    // Icon
    sf::Image windowIcon;
    windowIcon.loadFromFile("textures/icon.png");
    window->setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

    // Create Textures
    TextureLibrary textureLibrary;
    textureLibrary.LoadFromFile();
    textureLibrary.SetSprite();

    // Delta time setup
    sf::Clock clock;

    // GameManager
    int gameState = 0;

    // Assing screen width and height
    unsigned int screenWidth = window->getSize().x;
    unsigned int screenHeight = window->getSize().y;
    float screenWidthFloat = static_cast<float>(screenWidth);
    float screenHeightFloat = static_cast<float>(screenHeight);

    GameManager gameManager(window, &textureLibrary, screenWidthFloat, screenHeightFloat);

    // BackgroundSprites
    sf::Sprite bgSprite;
    sf::Sprite loseSprite;
    sf::Sprite winSprite;
    bgSprite.setTexture(textureLibrary.BgTexture);
    loseSprite.setTexture(textureLibrary.LoseTexture);
    winSprite.setTexture(textureLibrary.WinTexture);

    loseSprite.setScale(screenWidthFloat / textureLibrary.LoseTexture.getSize().x, screenHeightFloat / textureLibrary.LoseTexture.getSize().y);
    winSprite.setScale(screenWidthFloat / textureLibrary.WinTexture.getSize().x, screenHeightFloat / textureLibrary.WinTexture.getSize().y);

    // Game loop
    while (window->isOpen())
    {
        // Event handling
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        // Draw
        window->clear();

        switch (gameState)
        {
        case 0:
            window->draw(bgSprite);
            break;
        case 1:
            window->draw(loseSprite);
            break;
        case 2:
            window->draw(winSprite);
            break;
        }

        // Update
        sf::Time deltaTime = clock.restart();
        float deltaTimeInSeconds = deltaTime.asSeconds();

        if (gameState == 0)
        {
            gameManager.Update(deltaTimeInSeconds);
            gameState = gameManager.GameState;
        }

        window->display();
    }

    return 0;
}
