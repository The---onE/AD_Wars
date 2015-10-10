#pragma once

#include "Global.h"
#include "Data/Data.h"

class InformationLayer : public Layer
{
protected:
	Label* timeLabel;
	Label* selfAtkLabel;
	Label* selfDefLabel;
	Label* enemyAtkLabel;
	Label* enemyDefLabel;

	Label* dpsLabel;
	Label* randsLabel;

	Sprite* test;

	Sprite* selfHealthSprite;
	Sprite* enemyHealthSprite;
	Label* selfHealthLabel;
	Label* enemyHealthLabel;
	float healthScaleBase;
	float enemyHealthScaleBase;

	void createSelfHealth(int health, int healthMax);
	void createEnemyHealth(int health, int healthMax);

public:
	CREATE_FUNC(InformationLayer);
	bool init();

	void initTimeLabel();
	void showTime(float t);

	void createInformation();

	void createSelfAtk(int a);
	void createSelfDef(int d);
	void createEnemyAtk(int a);
	void createEnemyDef(int d);

	void showSelfDamage(int d);
	void showEnemyDamage(int d);

	void changeSelfHealth(int health, int healthMax);
	void changeEnemyHealth(int health, int healthMax);

};

