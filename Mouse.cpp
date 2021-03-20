#include "DXUT.h"
#include "Mouse.h"


Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

void Mouse::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 5, 5);
	OBJECT->AddCollsion(collider);
}

void Mouse::Update()
{
	dir += 0.01;
	if (dir >= 360)
		dir = 0;
	collider->SetRange(vPos, 5, 5);

	vPos = INPUT->GetMousePos();
}

void Mouse::Render()
{
	IMAGE->FindImage("MousePoint")->CenterRender(vPos, dir);
}

void Mouse::Release()
{
	SAFE_DELETE(collider);
}

void Mouse::onCollisionStay(Object * obj)
{

}

void Mouse::onCollisionExit(Object * obj)
{
}
