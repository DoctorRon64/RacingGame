#include "RigidBody.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"

using namespace v2P;

RigidBody::RigidBody() :
    position(0.0f, 0.0f), speed(0.0f), friction(0.0f), gravity(9.81f), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), mass(0.0f), forces(0.0f, 0.0f)
{

}

RigidBody::RigidBody(float x, float y, float s, float f, float m) :
    position(x, y), speed(s), friction(f), gravity(9.81f), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), mass(m), forces(0.0f, 0.0f)
{

}

void RigidBody::ApplyForce(const Vector2& force)
{
    forces += force;
}

void RigidBody::Update(float deltaTime)
{
    float amplitude = 0.01f;
    float frequency = 0.02f;
    float offsetX = amplitude * std::sin(frequency * position.y);
    position.x += offsetX;

    //V = speed
    //a = gravity;
    velocity = Vector2(0, speed);
    acceleration = Vector2(0, -gravity);

    // Apply friction
    velocity.y -= friction * velocity.y * deltaTime;

    // Apply forces with a = F / m
    acceleration += forces / mass;
    forces = Vector2(0.0f, 0.0f);

    // Update velocity and position with v = a * t and s = v * t
    velocity += acceleration * deltaTime;
    position.y += velocity.y * deltaTime;
}

Vector2 RigidBody::getPosition()
{
    return position;
}