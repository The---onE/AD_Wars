#include "StartScene.h"
#include "GameScene.h"
#include "Scene/SetScene.h"

bool StartScene::init()
{
	Scene::init();

	Label* startLable = Label::createWithTTF("Start Game", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* startGame = MenuItemLabel::create(startLable, CC_CALLBACK_0(StartScene::StartGame, this));

	Label* setLable = Label::createWithTTF("Setting", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* setGame = MenuItemLabel::create(setLable, CC_CALLBACK_0(StartScene::SetGame, this));

// 	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
// 		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Label* playLable = Label::createWithTTF("Play BGM", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* playBGM = MenuItemLabel::create(playLable);
	Label* stopLable = Label::createWithTTF("Stop BGM", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* stopBGM = MenuItemLabel::create(stopLable);
	MenuItemToggle* bgm = MenuItemToggle::createWithCallback(CC_CALLBACK_0(StartScene::PlayStopBGM, this), playBGM, stopBGM, NULL);

	effectFlag = false;
	Label* openEffectLable = Label::createWithTTF("Open Effect", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* openEffect = MenuItemLabel::create(openEffectLable);
	Label* closeEffectLable = Label::createWithTTF("Close Effect", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* closeEffect = MenuItemLabel::create(closeEffectLable);
	MenuItemToggle* effect = MenuItemToggle::createWithCallback(CC_CALLBACK_0(StartScene::OpenCloseEffect, this), openEffect, closeEffect, NULL);

	Label* quitLable = Label::createWithTTF("Quit Game", INFORMATION_FONT, INFORMATION_FONTSIZE);
	MenuItemLabel* quitGame = MenuItemLabel::create(quitLable, CC_CALLBACK_0(StartScene::QuitGame, this));

	Menu* mainMenu = Menu::create(startGame, setGame, bgm, effect, quitGame, NULL);
	mainMenu->alignItemsVerticallyWithPadding(20);
	this->addChild(mainMenu, 1);

	createBackGround(BACKGROUND_IMG);

	return true;
}

void StartScene::StartGame()
{
	GameScene* game = GameScene::create();
	//game->setEffectFlag(effectFlag);
	Director::getInstance()->pushScene(game);
}

void StartScene::SetGame()
{
	SetScene* set = SetScene::create();
	//game->setEffectFlag(effectFlag);
	Director::getInstance()->pushScene(set);
}

void StartScene::PlayStopBGM()
{
// 	SimpleAudioEngine* audio = SimpleAudioEngine::getInstance();
// 	if (audio->isBackgroundMusicPlaying())
// 	{
// 		audio->stopBackgroundMusic();
// 	}
// 	else
// 	{
// 		audio->playBackgroundMusic("musics/bgm.mp3");
// 	}
}

void StartScene::OpenCloseEffect()
{
	/*effectFlag = !effectFlag;*/
}

void StartScene::QuitGame()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void StartScene::createBackGround(string filename)
{
	Sprite* bG = Sprite::create(filename);
	bG->setPosition(BACKGROUND_POSITION);
	setSize(bG, BACKGROUND_SIZE);
	addChild(bG);
}