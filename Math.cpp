#include "DXUT.h"
#include "Math.h"


Math::Math()
{
}


Math::~Math()
{
}

Vector2 Math::Rotate(Vector2 v, float rot)
{
	float _rot = D3DXToDegree(rot);
	return Vector2(v.x * cos(_rot) + v.y * -sin(_rot), v.x * sin(_rot) + v.y * cos(rot));
}

float Math::Direction(Vector2 v1, Vector2 v2)
{
	return D3DXToDegree(atan2f(v2.y - v1.y, v2.x - v1.x));
}

void Math::Bazier(Vector2 * target, Vector2 & start,Vector2& control ,Vector2 & finsh)
{
	Vector2 v1, v2, v3;
	v1 = start;
	v2 = control;
	Lerp<Vector2>(&v1, v1, v2, 1);
	Lerp<Vector2>(&v2, v2, finsh, 1);
	Lerp<Vector2>(&v3, v1, v2,1);
}
