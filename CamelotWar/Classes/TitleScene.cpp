#include "TitleScene.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
	return TitleScene::create();
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("scene/background.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setContentSize(visibleSize);
	addChild(background);

	auto spriteTheCamelot = Sprite::create("scene/theCamelot.png");
	spriteTheCamelot->setPosition(Vec2(SCENE_TITLE_THECAMELOT_W, SCENE_TITLE_THECAMELOT_H));
	addChild(spriteTheCamelot);

	// Create play item
	auto Play = MenuItemImage::create("scene/play.png", "scene/play.png", CC_CALLBACK_1(TitleScene::menuPlayCallback, this));
	Play->setPosition(Vec2(SCENE_TITLE_PLAY_W, SCENE_TITLE_PLAY_H));
	
	// Create exit item
	auto Exit = MenuItemImage::create("scene/exit.png", "scene/exit.png", CC_CALLBACK_1(TitleScene::menuPlayCallback, this));
	Exit->setPosition(Vec2(SCENE_TITLE_EXIT_W, SCENE_TITLE_EXIT_H));

	// Create setting item
	auto Setting = MenuItemImage::create("scene/setting.png", "scene/setting.png", CC_CALLBACK_1(TitleScene::menuPlayCallback, this));
	Setting->setPosition(Vec2(SCENE_TITLE_SETTING_W, SCENE_TITLE_SETTING_H));

	// Set item to menu
	auto Menu = Menu::create(Play, Setting, Exit , NULL);
	Menu->setPosition(Vec2::ZERO);
	addChild(Menu);

	return true;
}


void TitleScene::menuPlayCallback(Ref* pSender)
{

}