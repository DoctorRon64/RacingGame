#include "Vector2.h"
using namespace Vector2P;

Vector2::Vector2(float _x, float _y) : x(_x), y(_y)
{

};

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
	if (x == other.x && y == other.y) { return true; }
	return false;
}

bool Vector2::operator!=(const Vector2& other) const
{
	if (x != other.x && y != other.y) { return true; }
	return false;
}

float Vector2::SqrtMagnitude(const Vector2& other)
{
	return other.x * other.x + other.y * other.y; //c^2
}

float Vector2::Magnitude(const Vector2& other)
{
	return sqrt(other.x * other.x + other.y * other.y); //c
}

float Vector2::DotProduct(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

sf::Vector2f Vector2::ToSFMLVector2()
{
	return sf::Vector2f(x, y);
}

