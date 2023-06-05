#pragma once
#include <SFML/Graphics.hpp>

class RigidBody
{
private:
    sf::Vector2f position;
    float speed;
    float friction;
    float gravity;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;
    sf::Vector2f forces;

public:
    RigidBody(float x, float y, float s, float f, float m);
    void ApplyForce(const sf::Vector2f& force);
    void Update(float deltaTime);
    sf::Vector2f getPosition();
};
