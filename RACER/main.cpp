#include "TextureLibrary.h"
#include "GameManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <string>
#include <Windows.h>

std::string getCurrentTimeAsString() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    struct tm timeinfo;
    localtime_s(&timeinfo, &currentTime);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);

    return std::string(buffer);
}

bool isFileEmpty(const std::string& filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}

void saveScoreToFile(std::string HighScoreName, int score) {
    std::string filename = "highscore.txt";
    std::ofstream outputFile(filename, std::ios::app);

    if (outputFile.is_open()) {
        std::string currentDate = getCurrentTimeAsString();

        if (isFileEmpty(filename)) {
            outputFile << "====== High Scores ======" << std::endl;
        }

        outputFile << "Score: " << score << " Date Made: " << currentDate << " By: " << HighScoreName << std::endl;
        outputFile.close();
        //std::cout << "Score saved to file." << std::endl;
    }
    else {
        std::cout << "Failed to save score to file." << std::endl;
    }
}

void displayFileContents(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    }
    else {
        std::cout << "Failed to open file: " << filename << std::endl;
    }
}

int main()
{
    std::string highScoreName;
    displayFileContents("Highscore.txt");

    // Render window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(960, 540), "SUPER ULTRA OMEGA ULTIMATE MEGA RACERRRRRRR!!!!!!!", sf::Style::Close | sf::Style::Resize);
    sf::View view(window->getDefaultView());

    // Icon
    sf::Image windowIcon;
    windowIcon.loadFromFile("textures/icon.png");
    window->setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

    // Create Textures
    TextureLibrary* textureLibrary = new TextureLibrary();
    textureLibrary->LoadFromFile();

    // Delta time setup
    sf::Clock clock;

    // GameManager
    int gameState = 0;

    // Assing screen width and height
    unsigned int screenWidth = window->getSize().x;
    unsigned int screenHeight = window->getSize().y;
    float screenWidthFloat = static_cast<float>(screenWidth);
    float screenHeightFloat = static_cast<float>(screenHeight);

    GameManager gameManager(window, textureLibrary, screenWidthFloat, screenHeightFloat);

    // BackgroundSprites
    sf::Sprite bgSprite;
    sf::Sprite loseSprite;
    sf::Sprite winSprite;
    bgSprite.setTexture(textureLibrary->BgTexture);
    loseSprite.setTexture(textureLibrary->LoseTexture);
    winSprite.setTexture(textureLibrary->WinTexture);

    bgSprite.setScale(screenWidthFloat / textureLibrary->BgTexture.getSize().x, screenHeightFloat / textureLibrary->BgTexture.getSize().y);
    loseSprite.setScale(screenWidthFloat / textureLibrary->LoseTexture.getSize().x, screenHeightFloat / textureLibrary->LoseTexture.getSize().y);
    winSprite.setScale(screenWidthFloat / textureLibrary->WinTexture.getSize().x, screenHeightFloat / textureLibrary->WinTexture.getSize().y);

    gameState = 0;

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
            view.zoom(.1f);


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {   
                window->close();
            }

            view.zoom(1.0f);

            break;
        case 2:
            window->draw(winSprite);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window->close();
            }
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

    if (!window->isOpen())
    {
        std::cout << "Enter your High Score Name: ";
        std::getline(std::cin, highScoreName);

        std::cout << "Your score was saved on: " << highScoreName << std::endl;
    }
    
    saveScoreToFile(highScoreName, gameManager.Score);
    delete window;

    return 0;
}
