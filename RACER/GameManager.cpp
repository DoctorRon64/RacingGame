#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow* window, TextureLibrary* TLib, float sW, float sH)
{
    screenWidth = sW;
    screenHeight = sH;
    textureLibrary = TLib;

    float randomValue = randomFloat(0, screenWidth);
    CreateCar();
    carWidth = car->getCarWidth();

    CarAmount = 10;

    player = new Player(500, (sH - 100), 0.12f, 0.12f, 2000, 4.0f, 1, textureLibrary->PlayerSprite);

    Score = 0;
    GameState = 0;
}

void GameManager::Update(sf::RenderWindow* window, float deltaTime)
{
    player->update(deltaTime, window);

    if (car == nullptr || car->CheckIfDeath(window))
    {
        delete car;
        car = nullptr;
        Score++;

        for (int i = 0; i < CarAmount; i++)
        {
            CreateCar();
        }
    }
    else
    {
        car->update(window, deltaTime);
    }

    if (Score >= 10 && GameState != 1)
    {
        GameState = 1;
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
    float maxSize = randomFloat(0, screenWidth - carWidth);
    car = new Car(maxSize, -100, 0.1f, 0.1f, randomFloat(400, 600), 30, 10, textureLibrary->CarSprite);
}
