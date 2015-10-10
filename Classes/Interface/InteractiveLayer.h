#pragma once

#include "Global.h"
#include "Data/Data.h"

class InterativeLayer : public Layer
{
protected:
	Sprite* attackSprite;
	Sprite* defenceSprite;

	Rect attackRect;
	Rect defenceRect;

	bool touchableFlag;
	bool touchedFlag;

	bool counterFlag;

	int choose;

public:
	CREATE_FUNC(InterativeLayer);
	bool init();
	void onEnter();
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

	void forbidTouch();
	void allowTouch();

	void initAttack();
	void initDefense();

	void changeToCounter();
	void changeToAD();

	bool checkTouched();
	int getChoose();
};

