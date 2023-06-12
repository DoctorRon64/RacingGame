#pragma once

namespace v2P {
    class Vector2;
}

class CollisionDetect
{
public:
    CollisionDetect(float r1, float r2);
    float ReturnDetectValue(v2P::Vector2& v1, v2P::Vector2& v2);

private:
    const float Radius1;
    const float Radius2;
};