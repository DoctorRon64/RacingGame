#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class RigidBody
{
private:
    Vector2P::Vector2 position;
    float speed;
    float friction;
    float gravity;
    Vector2P::Vector2 velocity;
    Vector2P::Vector2 acceleration;
    float mass;
    Vector2P::Vector2 forces;

public:
    RigidBody(float x, float y, float s, float f, float m);
    void ApplyForce(const Vector2P::Vector2& force);
    void Update(float deltaTime);
    Vector2P::Vector2 getPosition();
};
