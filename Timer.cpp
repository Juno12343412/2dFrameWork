#include "DXUT.h"
#include "Timer.h"


Timer::Timer()
{
}


Timer::~Timer()
{
}

bool Timer::Update()
{
	m_start += D_TIME;
	if (m_start > m_delay) {
		m_start = 0.f;
		return TRUE;
	}
	return FALSE;
}
