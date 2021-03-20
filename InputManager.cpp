#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(Last, Current, sizeof(Current));

	for (int i = 0; i < 256; i++)
	{
		Current[i] = false;
		if (GetAsyncKeyState(i))
		{
			Current[i] = true;
		}
	}
}

bool InputManager::KeyDown(BYTE key)
{
	return Current[key] && !Last[key];
}

bool InputManager::KeyUp(BYTE key)
{
	return !Current[key] && Last[key];

}

bool InputManager::KeyPress(BYTE key)
{
	return Current[key] && Last[key];

}

Vector2 InputManager::GetMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(DXUTGetHWND(), &pt);
	Vector2 mousepos(pt.x, pt.y);
	mousepos -= Vector2(WINSIZEX / 2 - CAMERA->m_vCameraPos.x, WINSIZEY / 2 - CAMERA->m_vCameraPos.y);
	return mousepos;
}

POINT InputManager::ptGetMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(DXUTGetHWND(), &pt);
	return pt;
}
