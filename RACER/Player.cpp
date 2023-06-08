#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"

using namespace v2P;

Player::Player(float x, float y, float w, float h, float s, float f, float m, const sf::Sprite& spriteRef, sf::RenderWindow* win)
    : position(x, y), width(w), height(h), speed(s), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), friction(f), sprite(spriteRef), mass(m), forces(0.0f, 0.0f), window(win)
{
    sprite.setScale(width, height);
}

Vector2 Player::getPosition()
{
    return Vector2(position);
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

void Player::update(float sW, float deltaTime)
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
    const float leftBoundary = 0.0f;
    const float rightBoundary = sW - sprite.getGlobalBounds().width;
    position.x = clamp(position.x, leftBoundary, rightBoundary);

    draw();
}

void Player::draw()
{
    sprite.setPosition(position.x, position.y);
    window->draw(sprite);
}