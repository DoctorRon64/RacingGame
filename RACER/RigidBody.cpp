#include "RigidBody.h"
#include <SFML/Graphics.hpp>

RigidBody::RigidBody(float x, float y, float s, float f, float m)
{
    position = sf::Vector2f(x, y);
    speed = s;
    friction = f;
    gravity = 9.81f;
    velocity = sf::Vector2f(0.0f, 0.0f);
    acceleration = sf::Vector2f(0.0f, 0.0f);
    mass = m;
    forces = sf::Vector2f(0.0f, 0.0f);
}

void RigidBody::ApplyForce(const sf::Vector2f& force)
{
    forces += force;
}

void RigidBody::Update(float deltaTime)
{
    //V = speed
    //a = gravity;
    velocity = sf::Vector2f(0, speed);
    acceleration = sf::Vector2f(0, -gravity);

    // Apply friction
    velocity.y -= friction * velocity.y * deltaTime;

    // Apply forces with a = F / m
    acceleration += forces / mass;
    forces = sf::Vector2f(0.0f, 0.0f);

    // Update velocity and position with v = a * t and s = v * t
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
}

sf::Vector2f RigidBody::getPosition()
{
    return position;
}