#include "StateList.h"

bool DrawState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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