#pragma once
#include "singleton.h"
class Timer
{
public:
	Timer();
	~Timer();

	bool Update();
	float m_start = 0;
	float m_delay = 0;

	void setTimer(float vel) { m_delay = vel; }
};
