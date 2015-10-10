#include "InteractiveLayer.h"

bool InterativeLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		
		initAttack();
		initDefense();

		choose = NC;

		touchableFlag = true;
		touchedFlag = false;

		counterFlag = false;

		bRet = true;
	} while (0);
	return bRet;
}

void InterativeLayer::onEnter()
{
	do
	{
		Layer::onEnter();

		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(false);
		listener->onTouchBegan = CC_CALLBACK_2(InterativeLayer::onTouchBegan, this);
		listener->onTouchMoved = CC_CALLBACK_2(InterativeLayer::onTouchMoved, this);
		listener->onTouchEnded = CC_CALLBACK_2(InterativeLayer::onTouchEnded, this);
		listener->onTouchCancelled = CC_CALLBACK_2(InterativeLayer::onTouchEnded, this);

		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	} while (0);
}

bool InterativeLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (touchableFlag)
	{
		Point touchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
		if (attackRect.containsPoint(touchPoint))
		{
			touchedFlag = true;
			if (counterFlag)
			{
				changeToAD();
				choose = COUNTER;
				XMX::Vibrator::vibrate(TOUCH_VIBRATE_TIME);
			}
			else
			{
				choose = ATTACK;
				XMX::Vibrator::vibrate(TOUCH_VIBRATE_TIME);
			}
		}
		if (defenceRect.containsPoint(touchPoint))
		{
			touchedFlag = true;
			if (counterFlag)
			{
				changeToAD();
				choose = COUNTER;
				XMX::Vibrator::vibrate(TOUCH_VIBRATE_TIME);
			}
			else
			{
				choose = DEFENCE;
				XMX::Vibrator::vibrate(TOUCH_VIBRATE_TIME);
			}
		}
	}

	return false;
}

void InterativeLayer::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void InterativeLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	Point touchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
}

void InterativeLayer::forbidTouch()
{
	touchableFlag = false;
}

void InterativeLayer::allowTouch()
{
	touchableFlag = true;
}

void InterativeLayer::initAttack()
{
	attackSprite = Sprite::create(ATTACK_IMG);
	attackSprite->setPosition(ATTACK_POSITION);
	attackSprite->setAnchorPoint(ATTACK_ANCHON);
	setSize(attackSprite, ATTACK_SIZE);
	addChild(attackSprite);
	attackRect = attackSprite->getBoundingBox();
}

void InterativeLayer::initDefense()
{
	defenceSprite = Sprite::create(DEFENCE_IMG);
	defenceSprite->setPosition(DEFENCE_POSITION);
	defenceSprite->setAnchorPoint(DEFENCE_ANCHON);
	setSize(defenceSprite, DEFENCE_SIZE);
	addChild(defenceSprite);
	defenceRect = defenceSprite->getBoundingBox();
}

void InterativeLayer::changeToCounter()
{
	removeChild(attackSprite);
	attackSprite = Sprite::create(COUNTER_IMG);
	attackSprite->setPosition(ATTACK_POSITION);
	attackSprite->setAnchorPoint(ATTACK_ANCHON);
	setSize(attackSprite, ATTACK_SIZE);
	addChild(attackSprite);

	removeChild(defenceSprite);
	defenceSprite = Sprite::create(COUNTER_IMG);
	defenceSprite->setPosition(DEFENCE_POSITION);
	defenceSprite->setAnchorPoint(DEFENCE_ANCHON);
	setSize(defenceSprite, DEFENCE_SIZE);
	addChild(defenceSprite);

	counterFlag = true;
}

void InterativeLayer::changeToAD()
{
	removeChild(attackSprite);
	attackSprite = Sprite::create(ATTACK_IMG);
	attackSprite->setPosition(ATTACK_POSITION);
	attackSprite->setAnchorPoint(ATTACK_ANCHON);
	setSize(attackSprite, ATTACK_SIZE);
	addChild(attackSprite);

	removeChild(defenceSprite);
	defenceSprite = Sprite::create(DEFENCE_IMG);
	defenceSprite->setPosition(DEFENCE_POSITION);
	defenceSprite->setAnchorPoint(DEFENCE_ANCHON);
	setSize(defenceSprite, DEFENCE_SIZE);
	addChild(defenceSprite);

	counterFlag = false;
}

bool InterativeLayer::checkTouched()
{
	bool flag = touchedFlag;
	touchedFlag = false;
	return flag;
}

int InterativeLayer::getChoose()
{
	return choose;
}