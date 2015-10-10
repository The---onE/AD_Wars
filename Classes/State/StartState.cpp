#include "StateList.h"

bool StartState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
{
	if (time > 0)
		CHANGE_TO_STATE(InitState);
	return false;
}

bool StartState::entryState()
{
	return true;
}

void StartState::onUpdate(float dt)
{
	time += dt;
	//scene->timeLapseShow(dt);
}

bool StartState::exitState()
{
	return true;
}