#include "StateList.h"

bool ProcessState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (re == WIN)
		CHANGE_TO_STATE(WinState)
	else if (re == LOSE)
		CHANGE_TO_STATE(LoseState)
	else if (re == DRAW)
		CHANGE_TO_STATE(DrawState)
	else if (time > FALL_TIME)
		CHANGE_TO_STATE(WaitActState);
	return false;
}

bool ProcessState::entryState()
{
	re = scene->process();
	return true;
}

void ProcessState::onUpdate(float dt)
{
	time += dt;
	scene->timeLapseShow(dt);
}

bool ProcessState::exitState()
{
	return true;
}