#pragma once

#include "Global.h"
#include "Data/Data.h"
#include "Unit/ActUnit.h"

class EnemyActLayer : public Layer
{
protected:
	ActUnit* act[VISBLE_ACT_NUM];
	int actCount[ACT_COUNT];

public:
	CREATE_FUNC(EnemyActLayer);
	bool init();

	void initAct();

	int randAct(int maxGap);

	int getBottomAct();
	int removeBottomAct();
	int actFall();
	void appear(int a);
	int createAct(int a, int id);
	void changeToCounter(int id = 1);
};

