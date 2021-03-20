#include "DXUT.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager()
	:collisionTag{
		{ 0,0,0,0 },//	NONE	1
		{ 0,0,0,0 },//	UI		2
		{ 0,0,0,0 },//	MOUSE	3
		{ 0,0,0,0 },//	END,	4
	}
{
}


ObjectManager::~ObjectManager()
{
	for (int i = NONE + 1; i < END; i++)
	{
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();)
		{
			if ((*iter) == nullptr)
				iter++;
			(*iter)->Release();
			SAFE_DELETE(*iter);
			iter++;
		}
	}
}

void ObjectManager::Update()
{
	for (int i = NONE; i < END; i++)
	{
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();)
		{
			if ((*iter)->CheckDestroy())
			{
				ColliderList.remove((*iter)->collider);
				ColliderList.remove((*iter)->collider2);
				ColliderList.remove((*iter)->collider3);
				ColliderList.remove((*iter)->collider4);
				ColliderList.remove((*iter)->collider5);
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else if (IsMapOut(*iter))
			{
				ColliderList.remove((*iter)->collider);
				ColliderList.remove((*iter)->collider2);
				ColliderList.remove((*iter)->collider3);
				ColliderList.remove((*iter)->collider4);
				ColliderList.remove((*iter)->collider5);
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else
			{
				(*iter)->Update();
				iter++;
			}
		}
	}
	for (auto& iter = ColliderList.begin(); iter != ColliderList.end(); iter++)
	{
		CollisionCheck((*iter));
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < END; i++)
	{
		for (auto iter : ObjList[i])
			iter->Render();
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < END; i++)
	{
		for (auto iter : ObjList[i])
			iter->Release();
	}
}

void ObjectManager::CollisionCheck(Collider * collider)
{
	for (auto& iter = ColliderList.begin(); iter != ColliderList.end();)
	{
		if ((*iter) == nullptr) { ColliderList.remove((*iter)->lpGameObject->collider);  iter++; }
		if (collisionTag[collider->lpGameObject->m_Tag][(*iter)->lpGameObject->m_Tag])
		{
			RECT rc2;
			if (IntersectRect(&rc2, &collider->GetRect(), &(*iter)->GetRect()))
			{
				collider->lpGameObject->onCollisionStay((*iter)->lpGameObject);
			}
			else
			{
				collider->lpGameObject->onCollisionExit((*iter)->lpGameObject);
			}
		}
		iter++;
	}
}

void ObjectManager::ClearAllObjects()
{
	for (int i = NONE; i < END; i++) {
		for (auto iter : ObjList[i])
		{
			iter->isDestroy = true;
		}
	}
}
