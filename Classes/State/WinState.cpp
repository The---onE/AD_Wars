#include "StateList.h"

bool WinState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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