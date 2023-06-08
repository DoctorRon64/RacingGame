#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Player {
private:
    v2P::Vector2 velocity;
    v2P::Vector2 acceleration;
    v2P::Vector2 position;
    sf::Sprite sprite;
    float friction;
    float speed;
    float width, height;
    float mass;
    v2P::Vector2 forces;
    static float clamp(float value, float min, float max);
    sf::RenderWindow* window;

public:
    Player(float x, float y, float w, float h, float s, float f, float m, const sf::Sprite& spriteRef, sf::RenderWindow* win);
    v2P::Vector2 getPosition();
    void setSpeed(float s);
    void ApplyForce(const v2P::Vector2& force);
    void Input();
    void update(float sW, float deltaTime);
    void draw();
};