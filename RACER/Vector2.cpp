#include "Vector2.h"
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace v2P;

Vector2::Vector2(float _x, float _y) : x(_x), y(_y)
{

}

Vector2::Vector2(const Vector2& _v2)
{
    x = _v2.x;
    y = _v2.y;
}

Vector2::~Vector2()
{

}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scaler) const
{
    return Vector2(x * scaler, y * scaler);
}

Vector2 Vector2::operator/(float scaler) const
{
    return Vector2(x / scaler, y / scaler);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

bool Vector2::operator==(const Vector2& other) const
{
    return (x == other.x && y == other.y);
}

bool Vector2::operator!=(const Vector2& other) const
{
    return (x != other.x || y != other.y);
}

float Vector2::Magnitude(const Vector2& other)
{
    return std::sqrt(other.x * other.x + other.y * other.y); // c
}

float Vector2::DotProduct(const Vector2& other) const
{
    return x * other.x + y * other.y;
}

Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

sf::Vector2f Vector2::ToSFMLVector2()
{
    return sf::Vector2f(x, y);
}
