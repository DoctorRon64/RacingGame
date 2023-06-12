#include "GameManager.h"
#include <random>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

GameManager::GameManager(sf::RenderWindow* win, TextureLibrary* TLib, float sW, float sH)
    : window(win), screenWidth(sW), screenHeight(sH), textureLibrary(TLib), player(nullptr), Score(0), GameState(0)
{
    float randomValue = randomFloat(0, screenWidth);

    CarAmount = 3;

    SetText();

    player = new Player(500, (sH - 100), 0.12f, 0.12f, 2000, 4.0f, 1, textureLibrary->PlayerTexture, window);

    Car* carObj = new Car(-1000, -1000, .1f, .1f, 0, 1, 0, textureLibrary->CarTexture, window);
    carWidth = carObj->getCarWidth();
    delete carObj;

    colletect = new CollisionDetect(5, 5);
    carList = std::vector<Car*>();

    CreateCars();
}

GameManager::~GameManager()
{
    delete player;
    delete textureLibrary;
    delete colletect;

    for (int i = 0; i < carList.size(); i++)
    {
        carList.erase(carList.begin() + i);
        delete carList[i];
    }
}

void GameManager::Update(float deltaTime)
{
    player->update(screenWidth, deltaTime);

    for (int i = 0; i < carList.size(); i++)
    {
        carList[i]->update(deltaTime);

        if (colletect->ReturnDetectValue(player->getPosition(), carList[i]->getPosition()) <= 0)
        {
            Score++;
            ScoreToEnd++;
            carList.erase(carList.begin() + i);
            delete carList[i];
        }

        if (carList[i]->CheckIfDeath(screenHeight) == true)
        {
            ScoreToEnd++;
            carList.erase(carList.begin() + i);
            delete carList[i];
            CreateCars();
        }
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

    scoreDisplay.setString(std::to_string(Score));
    std::cout << scoreDisplay.getString().toAnsiString() << std::endl;

    window->draw(scoreDisplay);
    window->draw(TextDisplay);
}

void GameManager::CreateCars()
{
    for (int i = 0; i < CarAmount; i++)
    {
        float maxSize = randomFloat(0, screenWidth - carWidth);
        carList.push_back(new Car(maxSize, -100, .1f, .1f, randomFloat(400, 600), 30, 10, textureLibrary->CarTexture, window));
    }
}

float GameManager::randomFloat(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}



void GameManager::SetText()
{
    scoreDisplay.setFont(textureLibrary->fontBold);
    scoreDisplay.setCharacterSize(25);
    scoreDisplay.setFillColor(sf::Color::Black);
    scoreDisplay.setStyle(sf::Text::Underlined);
    scoreDisplay.setPosition(175, 10);

    TextDisplay.setFont(textureLibrary->font);
    TextDisplay.setCharacterSize(25);
    TextDisplay.setFillColor(sf::Color::Black);
    TextDisplay.setPosition(10, 10);
    TextDisplay.setString("Your Score is: ");
}
