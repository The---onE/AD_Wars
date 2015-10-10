#include "EnemyActLayer.h"

bool EnemyActLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		initAct();

		bRet = true;
	} while (0);
	return bRet;
}

void EnemyActLayer::initAct()
{
	for (int i = 0; i < ACT_COUNT; ++i)
		actCount[i] = 0;
	for (int i = 0; i < VISBLE_ACT_NUM; ++i)
	{
		int a = randAct(MAX_GAP);
		createAct(a, i);
		act[i]->appear(FALL_TIME);
	}
}

int EnemyActLayer::randAct(int maxGap)
{
	int num[ACT_COUNT];
	int max = 0;
	int min = 0x7FFFFFFF;
	for (int i = 0; i < ACT_COUNT; ++i)
	{
		int temp = actCount[i];
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	}
	if (max - min < maxGap)
		max++;
	for (int i = 0; i < ACT_COUNT; ++i)
	{
		num[i] = max - actCount[i];
	}

	return randNum(ACT_COUNT, num);
}

int EnemyActLayer::getBottomAct()
{
	return act[0]->getAct();
}

int EnemyActLayer::removeBottomAct()
{
	int a = act[0]->getAct();
	removeChild(act[0]);
	return a;
}

int EnemyActLayer::actFall()
{
	int re = removeBottomAct();
	for (int i = 0; i < VISBLE_ACT_NUM - 1; ++i)
	{
		act[i] = act[i + 1];
		act[i]->moveToPosition(getCenterByIndex(i), FALL_TIME);
	}
	int a = randAct(MAX_GAP);
	appear(a);

	return re;
}

int EnemyActLayer::createAct(int a, int id)
{
	ActUnit* &temp = act[id];
	temp = ActUnit::create();
	actCount[a]++;
	temp->createAct(a, getCenterByIndex(id));
	addChild(temp);

	return a;
}

void EnemyActLayer::appear(int a)
{
	int top = VISBLE_ACT_NUM - 1;
	createAct(a, top);
	act[top]->appear(FALL_TIME);
}

void EnemyActLayer::changeToCounter(int id /* = 1 */)
{
	removeChild(act[id]);
	createAct(COUNTER, id);
}