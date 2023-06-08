#include "GameManager.h"
#include <random>
#include <iostream>
#include "CollisionDetect.h"

GameManager::GameManager(sf::RenderWindow* win, TextureLibrary* TLib, float sW, float sH)
    : window(win), screenWidth(sW), screenHeight(sH), textureLibrary(TLib), player(nullptr), car(nullptr), Score(0), GameState(0)
{
    float randomValue = randomFloat(0, screenWidth);
    CreateCar();
    carWidth = car->getCarWidth();

    CarAmount = 10;

    player = new Player(500, (sH - 100), 0.12f, 0.12f, 2000, 4.0f, 1, textureLibrary->PlayerSprite, window);
}

GameManager::~GameManager() 
{
    delete player;
    delete car;
    delete textureLibrary;
}

void GameManager::Update(float deltaTime)
{
    player->update(screenWidth, deltaTime);
    CollisionDetect* colletect = new CollisionDetect(player->getPosition(), 100, car->getPosition(), 100);

    if (colletect->ReturnDetectValue() <= 0)
    {
        delete car;
        delete colletect;
        Score++;
    }
    
    if (car == nullptr || car->CheckIfDeath(screenHeight))
    {
        delete car;
        car = nullptr;
        Score--;

        for (int i = 0; i < CarAmount; i++)
        {
            CreateCar();
        }
    }
    else
    {
        car->update(deltaTime);
    }

    if (Score >= 5 && GameState != 2)
    {
        GameState = 2;
        delete player;
    }

    if (Score <= -5 && GameState != 1) 
    {
        GameState = 1;
        delete player;
    }
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
    if (car != nullptr)
    {
        delete car;
        car = nullptr;
    }

    float maxSize = randomFloat(0, screenWidth - carWidth);
    car = new Car(maxSize, -100, 0.1f, 0.1f, randomFloat(400, 600), 30, 10, textureLibrary->CarSprite, window);
}
