#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Player
{
private:
    Vector2P::Vector2 velocity;
    Vector2P::Vector2 acceleration;
    Vector2P::Vector2 position;
    sf::Sprite sprite;
    float friction;
    float speed;
    float width, height;
    float mass;
    Vector2P::Vector2 forces;
    static float clamp(float value, float min, float max);

public:
    Player(float x, float y, float w, float h, float s, float f, float m, sf::Sprite spriteRef);  // Updated constructor
    void setSpeed(float s);
    void ApplyForce(const Vector2P::Vector2& force);
    void Input();
    void update(float deltaTime, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);
};