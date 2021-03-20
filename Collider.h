#pragma once
#include "Object.h"
class Object;

class Collider :
	public RECT
{
public:
	Collider();
	virtual ~Collider();

	Object* lpGameObject = nullptr;

	void Init();
	void SetRange(Vector2 Pos,float width, float height);

	

	RECT GetRect()
	{
		RECT rt;


		rt.left = left;
		rt.right = right;
		rt.top = top;
		rt.bottom = bottom;
		return rt;
	}
};

