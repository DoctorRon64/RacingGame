#pragma once
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
        Vector2 operator==(const Vector2& other) const;
        Vector2 operator!=(const Vector2& other) const;

    };
};



