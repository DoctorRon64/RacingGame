#include "Vector2.h"
using namespace Vector2P;

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
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

Vector2 Vector2::operator==(const Vector2& other) const 
{
	return Vector2(x == other.x, y == other.y);
}

Vector2 Vector2::operator!=(const Vector2& other) const
{
	return Vector2(x != other.x, y != other.y);
}
