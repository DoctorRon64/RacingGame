#pragma once

namespace v2P {
    class Vector2;
}

class CollisionDetect
{
public:
    CollisionDetect(const v2P::Vector2& v1, float r1, const v2P::Vector2& v2, float r2);
    float ReturnDetectValue();

private:
    const v2P::Vector2& VectorOne;
    const v2P::Vector2& VectorTwo;
    const float Radius1;
    const float Radius2;
};