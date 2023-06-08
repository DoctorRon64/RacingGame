#pragma once
#include "Vector2.h"

class RigidBody
{
private:
    v2P::Vector2 position;
    float speed;
    float friction;
    float gravity;
    v2P::Vector2 velocity;
    v2P::Vector2 acceleration;
    float mass;
    v2P::Vector2 forces;

public:
    RigidBody();
    RigidBody(float x, float y, float s, float f, float m);
    void ApplyForce(const v2P::Vector2& force);
    void Update(float deltaTime);
    v2P::Vector2 getPosition();
};