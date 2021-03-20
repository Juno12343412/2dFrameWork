#pragma once
#pragma comment(lib,"legacy_stdio_definitions.lib")
#pragma comment(lib,"dsound.lib")

#include <iostream>
#include <map>
#include <list>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

#define g_device DXUTGetD3D9Device()
#define D_TIME DXUTGetElapsedTime() * TimeScale

const int WINSIZEX = 1920;
const int WINSIZEY = 1080;

static bool isWindowed = true;
static float TimeScale = 1;

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;

#include "ImageManager.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Timer.h"
#include "CameraManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Math.h"
#include "World.h"