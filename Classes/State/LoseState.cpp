#include "StateList.h"

bool LoseState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	return false;
}

bool LoseState::entryState()
{
	scene->lose();
	return true;
}

void LoseState::onUpdate(float dt)
{
	time += dt;
}

bool LoseState::exitState()
{
	return true;
}