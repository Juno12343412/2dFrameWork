#pragma once
#include "singleton.h"
#include "Object.h"
class ObjectManager :
	public singleton<ObjectManager>
{
	friend class Object;
public:
	ObjectManager();
	virtual ~ObjectManager();

	list<Object*> ObjList[Tag::END];
	list<Collider*> ColliderList = {};

	bool collisionTag[END + 1][END + 1];

	Object* AddObject(const string& _Key, Object* _obj, Vector2 m_Pos, Tag _objTag)
	{
		_obj->m_Tag = _objTag;
		_obj->vPos = m_Pos;
		_obj->m_Key = _Key;
		_obj->Init();
		ObjList[_objTag].emplace_back(_obj);
		return _obj;
	}

	Object* FindObject(const string& _Key)
	{
		for (auto iter1 = 0; iter1 != Tag::END; iter1++)
			for (auto& iter2 : ObjList[iter1])
			{
				if (iter2->m_Key == _Key)
				{
					return iter2;
				}
			}
		return nullptr;
	}

	void AddCollsion(Collider* _collider) { ColliderList.emplace_back(_collider); }

	void Update();
	void Render();
	void Release();
	void CollisionCheck(Collider* collider);


	int IsMapOut(Object* obj)
	{
		if (obj->m_Tag == UI || obj->m_Tag == MOUSE)
		{
			return false;
		}
		else {
			return (obj->vPos.x < -100
				|| obj->vPos.x  > WINSIZEX + 300
				|| obj->vPos.y < -300
				|| obj->vPos.y  > WINSIZEY);
		}
	}
	void ClearAllObjects();


};


#define OBJECT ObjectManager::GetInstance()