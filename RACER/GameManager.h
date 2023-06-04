#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Player.h"
#include "Car.h"
using namespace std;

class GameManager
{
private:
	Player* player;
	Car* car;
	float screenWidth;

public:
	GameManager(sf::RenderWindow* window, float sW);
	void Update(sf::RenderWindow* window, float deltaTime);
	float randomFloat(float min, float max);
	void CreateCar(float maxSize);
};