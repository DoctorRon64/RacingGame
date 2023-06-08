#include "CollisionDetect.h"
#include "Vector2.h"
#include <cmath>

using namespace v2P;

CollisionDetect::CollisionDetect(const Vector2& v1, float r1, const Vector2& v2, float r2)
    : VectorOne(v1), Radius1(r1), VectorTwo(v2), Radius2(r2)
{
}

float CollisionDetect::ReturnDetectValue()
{
    Vector2 VectorD = VectorTwo - VectorOne;
    float M = VectorD.Magnitude(VectorD);
    return M - (Radius1 + Radius2) * (Radius1 + Radius2);
}