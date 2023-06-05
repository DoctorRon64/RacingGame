#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Player.h"
#include "Car.h"
#include "TextureLibrary.h"

using namespace std;

class GameManager
{
private:
	Player* player;
	Car* car;
	TextureLibrary* textureLibrary;
	float screenWidth;
	float screenHeight;
	float carWidth;

public:
	GameManager(sf::RenderWindow* window, TextureLibrary* TLib, float sW, float sH);
	void Update(sf::RenderWindow* window, float deltaTime);
	float randomFloat(float min, float max);
	void CreateCar(float maxSize);

	int Score;
	int GameState;
};