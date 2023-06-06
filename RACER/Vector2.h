#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

namespace Vector2P {
    class Vector2
    {
    public:
        float x;
        float y;

        Vector2(float _x, float _y);
        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(float scaler) const;
        Vector2 operator/(float scaler) const;
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        sf::Vector2f ToSFMLVector2();

        bool operator==(const Vector2& other) const;
        bool operator!=(const Vector2& other) const;

        static float SqrtMagnitude(const Vector2& other);
        static float Magnitude(const Vector2& other);
        float DotProduct(const Vector2& other) const;
    };
};



