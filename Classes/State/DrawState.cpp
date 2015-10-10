#include "StateList.h"

bool DrawState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	return false;
}

bool DrawState::entryState()
{
	scene->tie();
	return true;
}

void DrawState::onUpdate(float dt)
{
	time += dt;
}

bool DrawState::exitState()
{
	return true;
}