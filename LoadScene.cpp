#include "DXUT.h"
#include "LoadScene.h"
#include <thread>
#include <mutex>
#include <string>
#define maxcount 1

mutex ImageListMutex;
mutex AniListMutex;

void LoadScene::Init()
{
	CAMERA->Reset();

#pragma region FirstLoading // 로딩씬 리소스 로딩
#pragma endregion
	//이미지 로드 
#pragma region SecondLoading // 게임 리소스 로딩
	for (int i = 0; i < 10000; ++i)
	{
		ImageLoad("MousePoint" + to_string(i), "Ui/Mouse");
	}
#pragma endregion
}

void LoadScene::Update()
{
	//이제 로딩이 끝나더라도 로딩 리스트를 비워주지 않으니, 불러온 개수를 통해 로딩이 끝났는지 확인
	if (maxImageCount == ImageCount)
	{
		std::cout << "로딩 종료" << std::endl;
		//SCENE->ChangeScene("stage1"); 로딩 끝났을때 하는 행동
		//PostQuitMessage(0);
	}
}

void LoadScene::Render()
{
	//IMAGE->FindImage("LoadingBar")->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, Vector2(ImageCount / maxImageCount, 1));
}

#pragma region MainCodes
LoadScene::LoadScene()
	: ThreadEnable(true)
{
	int threadCount = std::thread::hardware_concurrency();
	ImageThread.reserve(threadCount);
	AniThread.reserve(threadCount);
	for (int i = 0; i < threadCount; ++i)
	{
		ImageThread.push_back(thread([this]() {
			while (ThreadEnable)
			{
				unique_lock<mutex> lock(ImageListMutex);
				if (Imagelist.empty())
					continue;
				
				auto front = Imagelist.front();
				Imagelist.pop_front();
				lock.unlock();
				
				IMAGE->AddImage(front.m_Key, front.m_Path);
				ImageCount++;
			}
		}));

		AniThread.push_back(thread([this]() {
			while (ThreadEnable)
			{
				unique_lock<mutex> lock(AniListMutex);
				if (Anilist.empty())
					continue;

				auto front = Anilist.front();
				Anilist.pop_front();
				lock.unlock();

				IMAGE->ADDVECIMAGE(front.m_Key, front.m_Path, front.m_Size);
				ImageCount++;
			}
		}));
	}
}


LoadScene::~LoadScene()
{
	ThreadEnable = false;
	for (auto& iter : ImageThread)
		iter.join();
	for (auto& iter : AniThread)
		iter.join();
}


void LoadScene::Release()
{
}

void LoadScene::ImageLoad(const string & _Key, const string & _Path, int size)
{
	if (size == 0)
	{
		lock_guard<mutex> lock(ImageListMutex);
		Imagelist.push_back(Load(_Key, _Path));
	}
	else
	{
		lock_guard<mutex> lock(AniListMutex);
		Anilist.push_back(Load(_Key, _Path, size));
	}
	maxImageCount++;
}
#pragma endregion
