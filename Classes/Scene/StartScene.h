#pragma once

#include "Global.h"
#include "Data/Data.h"

class StartScene : public Scene
{
protected:
	void StartGame();
	void SetGame();
	void PlayStopBGM();
	void OpenCloseEffect();
	void QuitGame();
	void createBackGround(string filename);

	bool effectFlag;

public:
	CREATE_FUNC(StartScene);
	bool init();
};

