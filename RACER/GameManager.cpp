#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow* window, float sW)
{
	screenWidth = sW;
	float randomValue = randomFloat(0, screenWidth);
	CreateCar(randomValue);
	screenWidth = sW - car->getCarWidth();

	player = new Player(500, 400, 0.12f, 0.12f, 2000, 4.0f);
}

void GameManager::Update(sf::RenderWindow* window, float deltaTime)
{
	player->update(deltaTime, window);

	if (car != nullptr && car->CheckIfDeath(window))
	{
		delete car;
		car = nullptr;

		for (int i = 0; i < 3; i++)
		{
			float randomValue = randomFloat(0, screenWidth);
			CreateCar(randomValue);
		}
	}
	else if (car != nullptr)
	{
		car->update(window, deltaTime);
	}
}

float GameManager::randomFloat(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}

void GameManager::CreateCar(float maxSize)
{
	car = new Car(maxSize, -100, 0.1f, 0.1f, randomFloat(300,600), 4.0f);
}