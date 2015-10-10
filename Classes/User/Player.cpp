#include "PLayer.h"

bool Player::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Node::init());

		bRet = true;
	} while (0);
	return bRet;
}

void Player::setAtk(int a)
{
	atk = a;
}

int Player::getAtk()
{
	return atk;
}

void Player::setDef(int d)
{
	def = d;
}

int Player::getDef()
{
	return def;
}

void Player::setHealth(int h)
{
	healthMax = h;
	health = h;
}

int Player::changeHealth(int delta /* = 0 */)
{
	health += delta;
	if (health > healthMax)
		health = healthMax;
	if (health < 0)
		health = 0;
	return health;
}

int Player::getHealthMax()
{
	return healthMax;
}