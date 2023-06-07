#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace Vector2P;

Player::Player(float x, float y, float w, float h, float s, float f, float m, sf::Sprite spriteRef)
    : position(x, y), width(w), height(h), speed(s), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), friction(f), sprite(spriteRef), mass(m), forces(0.0f, 0.0f)
{
    sprite.setScale(width, height);
}

void Player::setSpeed(float s)
{
    speed = s;
}

void Player::ApplyForce(const Vector2& force)
{
    forces += force;
}

float Player::clamp(float value, float min, float max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

void Player::Input()
{
    // Set acceleration based on keyboard input
    acceleration = Vector2(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        acceleration.x = -speed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        acceleration.x = speed;
    }
}

void Player::update(float deltaTime, sf::RenderWindow* window)
{
    Input();

    // Apply friction
    velocity.x -= friction * velocity.x * deltaTime;

    // Apply forces
    acceleration += forces / mass;
    forces = Vector2(0.0f, 0.0f);

    // Update velocity and position
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;

    // Keep player within the boundaries of the window
    sf::Vector2u windowSize = window->getSize();
    const float leftBoundary = 0.0f;
    const float rightBoundary = windowSize.x - (sprite.getTexture()->getSize().x * sprite.getScale().x);
    position.x = clamp(position.x, leftBoundary, rightBoundary);

    draw(window);
}

void Player::draw(sf::RenderWindow* window)
{
    sprite.setPosition(position.x, position.y);
    window->draw(sprite);
}