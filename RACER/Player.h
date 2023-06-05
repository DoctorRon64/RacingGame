#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f position;
    sf::Sprite sprite;
    float friction;
    float speed;
    float width, height;
    float mass;
    sf::Vector2f forces;
    static float clamp(float value, float min, float max);

public:
    Player(float x, float y, float w, float h, float s, float f, float m, sf::Sprite spriteRef);  // Updated constructor
    void setSpeed(float s);
    void ApplyForce(const sf::Vector2f& force);
    void Input();
    void update(float deltaTime, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);
};