#pragma once

#include "Global.h"
#include "Data/Data.h"

class Player : public Node
{
protected:
	int health;
	int healthMax;
	int atk;
	int def;

public:
	CREATE_FUNC(Player);
	bool init();

	void setAtk(int a);
	int getAtk();
	void setDef(int d);
	int getDef();
	void setHealth(int h);
	int changeHealth(int delta = 0);;
	int getHealthMax();
};