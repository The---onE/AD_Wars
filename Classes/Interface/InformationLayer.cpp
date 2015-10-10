#include "InformationLayer.h"

bool InformationLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		initTimeLabel();
		createSelfHealth(1, 1);
		createEnemyHealth(1, 1);
		createInformation();

		bRet = true;
	} while (0);
	return bRet;
}

void InformationLayer::createInformation()
{
	auto f = UserDefault::getInstance();
	int dps = f->getIntegerForKey(DAMAGE_PER_SECOND);
	int rands = UserDefault::getInstance()->getIntegerForKey(RANDOM_SEED, 0);
	if (rands == 0)
		rands = time(NULL) % 1000000;
	srand(rands);

	char text[32];
	sprintf(text, "DPS:%d", dps);
	dpsLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	dpsLabel->setColor(INFORMATION_COLOR);
	dpsLabel->setAnchorPoint(DPS_ANCHOR);
	dpsLabel->setPosition(DPS_POSITION);
	setSize(dpsLabel, INFORMATION_SIZE);
	addChild(dpsLabel);

	sprintf(text, "SEED:%d", rands);
	randsLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	randsLabel->setColor(INFORMATION_COLOR);
	randsLabel->setAnchorPoint(RANDOM_SEED_ANCHOR);
	randsLabel->setPosition(RANDOM_SEED_POSITION);
	setSize(randsLabel, INFORMATION_SIZE);
	addChild(randsLabel);
}

void InformationLayer::initTimeLabel()
{
	char text[32];
	sprintf(text, "TIME:0.0s");
	timeLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	timeLabel->setColor(TIME_COLOR);
	timeLabel->setAnchorPoint(TIME_ANCHOR);
	timeLabel->setPosition(TIME_POSITION);
	setSize(timeLabel, TIME_SIZE);
	addChild(timeLabel);
}

void InformationLayer::showTime(float t)
{
	char text[32];
	sprintf(text, "TIME:%.1fs", t);

	timeLabel->setString(text);
}

void InformationLayer::createSelfAtk(int a)
{
	char text[32];
	sprintf(text, "ATK:%d", a);
	selfAtkLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	selfAtkLabel->setColor(ATK_COLOR);
	selfAtkLabel->setAnchorPoint(SELF_ATK_ANCHOR);
	selfAtkLabel->setPosition(SELF_ATK_POSITION);
	setSize(selfAtkLabel, INFORMATION_SIZE);
	addChild(selfAtkLabel);
}

void InformationLayer::createSelfDef(int d)
{
	char text[32];
	sprintf(text, "DEF:%d", d);
	selfDefLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	selfDefLabel->setColor(DEF_COLOR);
	selfDefLabel->setAnchorPoint(SELF_DEF_ANCHOR);
	selfDefLabel->setPosition(SELF_DEF_POSITION);
	setSize(selfDefLabel, INFORMATION_SIZE);
	addChild(selfDefLabel);
}

void InformationLayer::createEnemyAtk(int a)
{
	char text[32];
	sprintf(text, "ATK:%d", a);
	selfAtkLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	selfAtkLabel->setColor(ATK_COLOR);
	selfAtkLabel->setAnchorPoint(ENEMY_ATK_ANCHOR);
	selfAtkLabel->setPosition(ENEMY_ATK_POSITION);
	setSize(selfAtkLabel, INFORMATION_SIZE);
	addChild(selfAtkLabel);
}

void InformationLayer::createEnemyDef(int d)
{
	char text[32];
	sprintf(text, "DEF:%d", d);
	selfDefLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	selfDefLabel->setColor(DEF_COLOR);
	selfDefLabel->setAnchorPoint(ENEMY_DEF_ANCHOR);
	selfDefLabel->setPosition(ENEMY_DEF_POSITION);
	setSize(selfDefLabel, INFORMATION_SIZE);
	addChild(selfDefLabel);
}

void InformationLayer::createSelfHealth(int health, int healthMax)
{
	char text[32];
	sprintf(text, "%d/%d", health, healthMax);
	selfHealthLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	selfHealthLabel->setColor(SELF_HEALTH_COLOR);
	selfHealthLabel->setAnchorPoint(Point(0.5, 1));
	selfHealthLabel->setPosition(SELF_HEALTH_POSITION);
	setSize(selfHealthLabel, HEALTH_SIZE);
	this->addChild(selfHealthLabel);

	selfHealthSprite = Sprite::create(SELF_HEALTH_IMG);
	selfHealthSprite->setAnchorPoint(Point(0, 1));
	selfHealthSprite->setPosition(Point(0, HEIGHT));
	setSize(selfHealthSprite, HEALTH_SIZE);
	healthScaleBase = WIDTH*0.5 / selfHealthSprite->getContentSize().width;
	selfHealthSprite->setScaleX(healthScaleBase*health / healthMax);
	this->addChild(selfHealthSprite, -1);
}

void InformationLayer::createEnemyHealth(int health, int healthMax)
{
	char text[32];
	sprintf(text, "%d/%d", health, healthMax);
	enemyHealthLabel = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	enemyHealthLabel->setColor(ENELM_HEALTH_COLOR);
	enemyHealthLabel->setAnchorPoint(Point(0.5, 1));
	enemyHealthLabel->setPosition(ENEMY_HEALTH_POSITION);
	setSize(enemyHealthLabel, HEALTH_SIZE);
	this->addChild(enemyHealthLabel);

	enemyHealthSprite = Sprite::create(ENEMY_HEALTH_IMG);
	enemyHealthSprite->setAnchorPoint(Point(1, 1));
	enemyHealthSprite->setPosition(Point(WIDTH, HEIGHT));
	setSize(enemyHealthSprite, HEALTH_SIZE);
	enemyHealthScaleBase = WIDTH*0.5 / enemyHealthSprite->getContentSize().width;
	enemyHealthSprite->setScaleX(enemyHealthScaleBase*health / healthMax);
	this->addChild(enemyHealthSprite, -1);
}

void InformationLayer::showSelfDamage(int d)
{
	char text[32];
	sprintf(text, "-%d", d);
	Label* l = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	l->setColor(DAMAGE_COLOR);
	l->setAnchorPoint(SELF_DAMAGE_ANCHOR);
	l->setPosition(SELF_DAMAGE_POSITION);
	setSize(l, DAMAGE_SIZE);
	this->addChild(l);

	Action* a = Sequence::create(MoveBy::create(FALL_TIME * 10, Point(0, HEIGHT*0.05f)), RemoveSelf::create(), NULL);
	l->runAction(a);
}

void InformationLayer::showEnemyDamage(int d)
{
	char text[32];
	sprintf(text, "-%d", d);
	Label* l = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	l->setColor(DAMAGE_COLOR);
	l->setAnchorPoint(ENEMY_DAMAGE_ANCHOR);
	l->setPosition(ENEMY_DAMAGE_POSITION);
	setSize(l, DAMAGE_SIZE);
	this->addChild(l);

	Action* a = Sequence::create(MoveBy::create(FALL_TIME * 10, Point(0, HEIGHT*0.05f)), RemoveSelf::create(), NULL);
	l->runAction(a);
}

void InformationLayer::changeSelfHealth(int health, int healthMax)
{
	char text[32];
	sprintf(text, "%d/%d", health, healthMax);
	selfHealthLabel->setString(text);

	if (health < 0)
		health = 0;
	selfHealthSprite->setScaleX(healthScaleBase*health / healthMax);
}

void InformationLayer::changeEnemyHealth(int health, int healthMax)
{
	char text[32];
	sprintf(text, "%d/%d", health, healthMax);
	enemyHealthLabel->setString(text);

	if (health < 0)
		health = 0;
	enemyHealthSprite->setScaleX(enemyHealthScaleBase*health / healthMax);
}