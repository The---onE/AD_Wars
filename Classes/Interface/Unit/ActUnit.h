#pragma once

#include "Global.h"
#include "Data/Data.h"

class ActUnit : public Node
{
protected:
	Sprite* actSprite;
	int act;
public:
	CREATE_FUNC(ActUnit);
	bool init();

	bool createAct(int a, Point pos);
	void moveToPosition(Point pos, float time);
	void appear(float time);

	int getAct();
};