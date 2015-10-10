#pragma once

#include "Global.h"
#include "StateMachine.h"
#include "Interface/Interface.h"
#include "User/User.h"

class GameScene : public Scene
{
protected:
	StateMachine* stateMachine; //状态机

	BackgroundLayer* background;
	InterativeLayer* interactive;
	InformationLayer* information;
	EnemyActLayer* enemyAct;

	int choose;
	int enemyChoose;

	Player* self;
	Player* enemy;

	float time;
	int damageTime;
	int damage;

public:
	CREATE_FUNC(GameScene);
	bool init();

	void initBackground();
	void initInteractive();
	void initInformation();
	void initEnemyAct();

	void initSelf();
	void initEnemy();

	void selfDamage(int d);
	void enemyDamage(int d);

	float timeLapse(float dt);
	void showTime(float t);
	void timeLapseShow(float dt);
	int damagePerSecond();

	void forbidTouch();
	void allowTouch();

	bool check();
	int process();

	void win();
	void lose();
	void tie();

	//////////////////////////////////////////////////////////////////////////
	void func();
	void func2();
	//////////////////////////////////////////////////////////////////////////


	StateMachine* getStateMachine(); //返回状态机指针
	void update(float dt);

	void createQuitButton(string normal, string selected);
	void quitGame(Ref* pSender); //退出游戏
};

