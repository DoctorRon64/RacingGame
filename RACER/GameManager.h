#pragma once
#include "Player.h"
#include "Car.h"
#include <SFML/Graphics.hpp>
#include "TextureLibrary.h"
#include "CollisionDetect.h"

using namespace std;

class GameManager
{
private:
    Player* player;
    TextureLibrary* textureLibrary;
    sf::RenderWindow* window;
    CollisionDetect* colletect;
    sf::Text scoreDisplay;
    sf::Text TextDisplay;
    std::vector<Car*> carList;
    float screenWidth;
    float screenHeight;
    float carWidth;

    void SetText();
    void CreateCars();

public:
    GameManager(sf::RenderWindow* win, TextureLibrary* TLib, float sW, float sH);
    ~GameManager();
    void Update(float deltaTime);
    float randomFloat(float min, float max);

    int Score;
    int ScoreToEnd;
    int GameState;
    int CarAmount;
};
