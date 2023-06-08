#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "RigidBody.h"

class Car
{
private:
    v2P::Vector2 position;
    float width, height;
    float speed;
    float friction;
    RigidBody rb;
    sf::Sprite sprite;
    sf::RenderWindow* window;

public:
    Car(float x, float y, float w, float h, float s, float f, float Carmass, sf::Sprite spriteRef, sf::RenderWindow* winD);
    void update(float deltaTime);
    v2P::Vector2 getPosition();
    bool CheckIfDeath(float sH);
    void DrawCar();
    float getCarWidth();
    float getCarHeight();
};