#include "StateList.h"

bool WinState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	return false;
}

bool WinState::entryState()
{
	scene->win();
	return true;
}

void WinState::onUpdate(float dt)
{
	time += dt;
}

bool WinState::exitState()
{
	return true;
}