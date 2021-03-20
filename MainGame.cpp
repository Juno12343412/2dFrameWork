#include "DXUT.h"
#include "MainGame.h"
#include "LoadScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	ShowCursor(false);

	CAMERA->Reset();
	SCENE->AddScene("loading", new LoadScene);

	SCENE->ChangeScene("loading");

}

void MainGame::Update()
{
	CAMERA->Update();
	SCENE->Update();
	OBJECT->Update();
	INPUT->Update();
}

void MainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Begin();

	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	ShowCursor(true);
	SceneManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	Math::ReleaseInstance();
	SoundManager::ReleaseInstance();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();

}
