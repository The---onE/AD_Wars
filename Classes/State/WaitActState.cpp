#include "StateList.h"

bool WaitActState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (scene->check())
		CHANGE_TO_STATE(ProcessState);
	return false;
}

bool WaitActState::entryState()
{
	scene->allowTouch();
	return true;
}

void WaitActState::onUpdate(float dt)
{
	time += dt;
	scene->timeLapseShow(dt);
}

bool WaitActState::exitState()
{
	scene->forbidTouch();
	return true;
}