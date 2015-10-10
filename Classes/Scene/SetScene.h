#pragma once

#include "Global.h"
#include "Data/Data.h"

class SetScene : public Scene
{
protected:
	Node* rootNode;

public:
	CREATE_FUNC(SetScene);
	bool init();
};

