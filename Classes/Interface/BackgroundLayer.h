#pragma once

#include "Global.h"
#include "Data/Data.h"

class BackgroundLayer : public Layer
{
protected:
	Sprite* bG; //����ͼƬ

public:
	CREATE_FUNC(BackgroundLayer);
	bool init();
	float getBGHeight();
};