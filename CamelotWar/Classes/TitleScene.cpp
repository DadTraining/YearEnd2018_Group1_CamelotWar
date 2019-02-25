#include "TitleScene.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"

#include "HelloWorldScene.h"

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

	auto background = Sprite::create(SCENE_TITLE_PNG_BACKGROUND);
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setContentSize(visibleSize);
	addChild(background);
  
	auto spriteTheCamelot = Sprite::create(SCENE_TITLE_PNG_THECAMELOT);
	spriteTheCamelot->setPosition(Vec2(SCENE_TITLE_THECAMELOT_W, SCENE_TITLE_THECAMELOT_H));
	addChild(spriteTheCamelot);

	// Create play item

	auto Play = MenuItemImage::create(SCENE_TITLE_PNG_PLAY, SCENE_TITLE_PNG_PLAY, CC_CALLBACK_1(TitleScene::menuPlayCallback, this));
	Play->setPosition(Vec2(SCENE_TITLE_PLAY_W, SCENE_TITLE_PLAY_H));
	
	// Create exit item
	auto Exit = MenuItemImage::create(SCENE_TITLE_PNG_EXIT, SCENE_TITLE_PNG_EXIT, CC_CALLBACK_1(TitleScene::menuPlayCallback, this));
	Exit->setPosition(Vec2(SCENE_TITLE_EXIT_W, SCENE_TITLE_EXIT_H));

	// Create setting item
	auto Setting = MenuItemImage::create(SCENE_TITLE_PNG_SETTING, SCENE_TITLE_PNG_SETTING, CC_CALLBACK_1(TitleScene::menuPlayCallback, this));
	Setting->setPosition(Vec2(SCENE_TITLE_SETTING_W, SCENE_TITLE_SETTING_H));

	// Set item to menu
	auto Menu = Menu::create(Play, Setting, Exit , NULL);
	Menu->setPosition(Vec2::ZERO);
	addChild(Menu);

	scheduleUpdate();

	return true;
}


void TitleScene::menuPlayCallback(Ref* pSender)
{
	return true;
}

void TitleScene::update(float delta)
{

}


void TitleScene::menuPlayCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}