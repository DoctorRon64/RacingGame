#include "CollisionDetect.h"
#include "Vector2.h"
#include <cmath>

using namespace v2P;

CollisionDetect::CollisionDetect(float r1, float r2)
    : Radius1(r1), Radius2(r2)
{

}

float CollisionDetect::ReturnDetectValue(Vector2& v1, Vector2& v2)
{
    Vector2 VectorD = v1 - v2;
    float M = VectorD.Magnitude(VectorD);
    return M - (Radius1 + Radius2) * (Radius1 + Radius2);
}