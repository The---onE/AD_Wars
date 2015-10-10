#include "ActUnit.h"

bool ActUnit::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Node::init());

		bRet = true;
	} while (0);
	return bRet;
}

bool ActUnit::createAct(int a, Point pos)
{
	if (a == ATTACK)
		actSprite = Sprite::create(ATTACK_IMG);
	else if (a == DEFENCE)
		actSprite = Sprite::create(DEFENCE_IMG);
	else if (a == COUNTER)
		actSprite = Sprite::create(COUNTER_IMG);
	else
		return false;
	act = a;
	actSprite->setPosition(Point::ZERO);
	this->setPosition(pos);
	setSize(actSprite, ACT_SIZE);
	this->addChild(actSprite);

	return true;
}

void ActUnit::moveToPosition(Point pos, float time)
{
	this->stopAllActions();
	Action* move = MoveTo::create(time, pos);
	this->runAction(move);
}

void ActUnit::appear(float time)
{
	actSprite->setScale(0);
	float sc = DATUM* ACT_SIZE / actSprite->getContentSize().height;
	Action* scale = ScaleTo::create(time, sc);
	actSprite->runAction(scale);
}

int ActUnit::getAct()
{
	return act;
}