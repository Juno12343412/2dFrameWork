#include "DXUT.h"
#include "Collider.h"


Collider::Collider()
{
}


Collider::~Collider()
{
}

void Collider::Init()
{

}

void Collider::SetRange(Vector2 pos,float width, float height)
{
	left = pos.x - width / 2;
	right = pos.x + width / 2;
	top = pos.y - height / 2;
	bottom = pos.y + height / 2;
}
