#include "StateList.h"

bool LoseState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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