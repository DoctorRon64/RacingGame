#pragma once
#include <SFML/Graphics.hpp>

namespace v2P {
    class Vector2
    {
    public:
        float x;
        float y;

        Vector2() : x(0.0f), y(0.0f) { }
        Vector2(float _x, float _y);
        Vector2(const Vector2& _v2);
        ~Vector2();
        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(float scaler) const;
        Vector2 operator/(float scaler) const;
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2 operator-() const;

        bool operator==(const Vector2& other) const;
        bool operator!=(const Vector2& other) const;

        sf::Vector2f ToSFMLVector2();
        static float Magnitude(const Vector2& other);
        float DotProduct(const Vector2& other) const;
    };
}