#include "StateList.h"

bool WaitActState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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