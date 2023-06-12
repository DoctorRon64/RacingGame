#include "GameManager.h"
#include <random>
#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>

GameManager::GameManager(sf::RenderWindow* win, TextureLibrary* TLib, float sW, float sH)
    : window(win), screenWidth(sW), screenHeight(sH), textureLibrary(TLib), player(nullptr), Score(0), GameState(0)
{
    float randomValue = randomFloat(0, screenWidth);

    CarAmount = 10;

    scoreDisplay = sf::Text();
    sf::Font font;
    font.loadFromFile("fonts/Gilroy-ExtraBold.otf");
    if (!font.loadFromFile("fonts/Gilroy-ExtraBold.otf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }
    scoreDisplay.setFont(font);
    scoreDisplay.setCharacterSize(20);
    scoreDisplay.setFillColor(sf::Color::White);
    scoreDisplay.setPosition(10, 10);
    scoreDisplay.setString(std::to_string(Score));



    player = new Player(500, (sH - 100), 0.12f, 0.12f, 2000, 4.0f, 1, textureLibrary->PlayerTexture, window);
    carObj = new Car(0, -100, .1f, .1f, randomFloat(400, 600), 30, 10, textureLibrary->CarTexture, window);
    colletect = new CollisionDetect(5, 5);

    carWidth = carObj->getCarWidth();
}

GameManager::~GameManager() 
{
    delete carObj;
    delete player;
    delete textureLibrary;
    delete colletect;
}

void GameManager::Update(float deltaTime)
{
    player->update(screenWidth, deltaTime);
    carObj->update(deltaTime);

    if (colletect->ReturnDetectValue(player->getPosition(), carObj->getPosition()) <= 0)
    {
        delete carObj;
        carObj = nullptr;
        ScoreToEnd++;
        CreateCar();
    }

    if (carObj->CheckIfDeath(screenHeight) == true)
    {
        delete carObj;
        carObj = nullptr;
        Score++;
        ScoreToEnd++;
        CreateCar();
    }

    if (ScoreToEnd >= 10)
    {
        if (Score >= ScoreToEnd / 2)
        {
            GameState = 2;
        }
        else
        {
            GameState = 1;
        }
    }
    std::cout << window << std::endl;


    window->draw(scoreDisplay);


    std::cout << window << std::endl;

}

float GameManager::randomFloat(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

void GameManager::CreateCar()
{
    float maxSize = randomFloat(0, screenWidth - carWidth);
    carObj = new Car(maxSize, -100, .1f, .1f, randomFloat(400, 600), 30, 10, textureLibrary->CarTexture, window);
}
