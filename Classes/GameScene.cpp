#include "GameScene.h"
#include "State/StateList.h"

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		time = 0;
		damageTime = 1;

		createQuitButton("QuitNormal.png", "QuitSelected.png");
		
		stateMachine = StateMachine::createWithGameScene(this);
		stateMachine->changeState(StartState::create(this));
		this->scheduleUpdate();

		//auto rootNode = CSLoader::createNode("MainScene.csb");
		//addChild(rootNode);

		bRet = true;
	} while (0);
	return bRet;
}

void GameScene::initBackground()
{
	background = BackgroundLayer::create();
	addChild(background);
}

void GameScene::initInteractive()
{
	interactive = InterativeLayer::create();
	addChild(interactive);
}

void GameScene::initInformation()
{
	information = InformationLayer::create();
	addChild(information);
}

void GameScene::initEnemyAct()
{
	enemyAct = EnemyActLayer::create();
	addChild(enemyAct);
}

void GameScene::initSelf()
{
	self = Player::create();
	auto f = UserDefault::getInstance();

	int atk = f->getIntegerForKey(SELF_ATK_DATA);
	self->setAtk(atk);
	information->createSelfAtk(atk);

	int def = f->getIntegerForKey(SELF_DEF_DATA);
	self->setDef(def);
	information->createSelfDef(def);

	int hea = f->getIntegerForKey(SELF_HEALTH_DATA);
	self->setHealth(hea);
	information->changeSelfHealth(hea, hea);

	addChild(self);
}

void GameScene::initEnemy()
{
	enemy = Player::create();
	auto f = UserDefault::getInstance();

	int atk = f->getIntegerForKey(ENEMY_ATK_DATA);
	enemy->setAtk(atk);
	information->createEnemyAtk(atk);

	int def = f->getIntegerForKey(ENEMY_DEF_DATA);
	enemy->setDef(def);
	information->createEnemyDef(def);

	int hea = f->getIntegerForKey(ENEMY_HEALTH_DATA);
	enemy->setHealth(hea);
	information->changeEnemyHealth(hea, hea);

	damage = f->getIntegerForKey(DAMAGE_PER_SECOND);

	addChild(enemy);
}

void GameScene::selfDamage(int d)
{
	information->changeSelfHealth(self->changeHealth(-d), self->getHealthMax());
	information->showSelfDamage(d);
}

void GameScene::enemyDamage(int d)
{
	information->changeEnemyHealth(enemy->changeHealth(-d), enemy->getHealthMax());
	information->showEnemyDamage(d);
}

float GameScene::timeLapse(float dt)
{
	time += dt;
	if (time > damageTime)
	{
		damageTime++;
		damagePerSecond();
	}
	return time;
}

void GameScene::showTime(float t)
{
	information->showTime(t);
}

void GameScene::timeLapseShow(float dt)
{
	showTime(timeLapse(dt));
}

int GameScene::damagePerSecond()
{
	int rest = self->changeHealth();
	if (rest <= damage)
		damage = 0;
	selfDamage(damage);
	rest = self->changeHealth();
	return rest;
}

void GameScene::forbidTouch()
{
	interactive->forbidTouch();
}

void GameScene::allowTouch()
{
	interactive->allowTouch();
}

bool GameScene::check()
{
	if (interactive->checkTouched())
	{
		enemyChoose = enemyAct->getBottomAct();
		choose = interactive->getChoose();
		return true;
	}
	return false;
}

int GameScene::process()
{
	if (enemyChoose == ATTACK)
	{
		if (choose == ATTACK)
		{
			selfDamage(enemy->getAtk());
			enemyDamage(self->getAtk());
			//
		}
		else if (choose == DEFENCE)
		{
			selfDamage(enemy->getAtk() - self->getDef());
			enemyAct->changeToCounter();
			//
		}
		else if (choose == COUNTER)
		{
			selfDamage(enemy->getAtk());
			//
		}
	}
	else if (enemyChoose == DEFENCE)
	{
		if (choose == ATTACK)
		{
			enemyDamage(self->getAtk() - enemy->getDef());
			interactive->changeToCounter();
			//
		}
		else if (choose == DEFENCE)
		{
			//
		}
		else if (choose == COUNTER)
		{
			//
		}
	}
	else if (enemyChoose == COUNTER)
	{
		if (choose == ATTACK)
		{
			enemyDamage(self->getAtk());
			//
		}
		else if (choose == DEFENCE)
		{
			//
		}
		else if (choose == COUNTER)
		{
			//
		}
	}
	enemyAct->actFall();

	int sh = self->changeHealth();
	int eh = enemy->changeHealth();

	if (sh <= 0)
	{
		if (eh <= 0)
			return DRAW;
		else
			return LOSE;
	}
	else
	{
		if (eh <= 0)
			return WIN;
	}

	return NE;
}

void GameScene::win()
{
	Sprite* r = Sprite::create(WIN_IMG);
	r->setPosition(RESULT_POSITON);
	setSize(r, RESULT_SIZE);
	addChild(r);
}

void GameScene::lose()
{
	Sprite* r = Sprite::create(LOSE_IMG);
	r->setPosition(RESULT_POSITON);
	setSize(r, RESULT_SIZE);
	addChild(r);
}

void GameScene::tie()
{
	Sprite* r = Sprite::create(DRAW_IMG);
	r->setPosition(RESULT_POSITON);
	setSize(r, RESULT_SIZE);
	addChild(r);
}

//////////////////////////////////////////////////////////////////////////
void GameScene::func()
{
}

void GameScene::func2()
{
}
//////////////////////////////////////////////////////////////////////////



StateMachine* GameScene::getStateMachine()
{
	return stateMachine;
}

void GameScene::update(float dt)
{
	stateMachine->update(dt);
}

void GameScene::createQuitButton(string normal, string selected)
{
	auto closeItem = MenuItemImage::create(normal, selected, CC_CALLBACK_1(GameScene::quitGame, this));
	closeItem->setPosition(Point(WIDTH / 2, 0));
	closeItem->setAnchorPoint(Point(0.5f, 0));
	setSize(closeItem, 0.08f);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
}

void GameScene::quitGame(Ref* pSender)
{
	Director::getInstance()->popScene();
}
