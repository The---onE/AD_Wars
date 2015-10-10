#include "StateList.h"

bool InitState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > FALL_TIME)
		CHANGE_TO_STATE(WaitActState);
	return false;
}

bool InitState::entryState()
{
	scene->initBackground();
	scene->initInteractive();
	scene->initInformation();
	scene->initEnemyAct();

	scene->initSelf();
	scene->initEnemy();

	return true;
}

void InitState::onUpdate(float dt)
{
	time += dt;
	scene->timeLapseShow(dt);
}

bool InitState::exitState()
{
	return true;
}