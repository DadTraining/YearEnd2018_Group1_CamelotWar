#include "Castle.h"
#include "Character.h"
#include "Defines.h"




Castle::Castle()
{
}

Castle::Castle(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create("tower.png");
	mSprite->setScale(0.6);
<<<<<<< HEAD
	setPos(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width/4, 330));
=======
	setPos(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width/4, 350));
>>>>>>> 6a81598ede25f14feb0143bd50e08df9f9795099
	scene->addChild(mSprite);

	mHpBar = cocos2d::Sprite::create("loading_bg.png");
	mHpBar->setScale(3);
<<<<<<< HEAD
	mHpBar->setPosition(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width / 4, 480));
=======
	mHpBar->setPosition(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width / 4, 400));
>>>>>>> 6a81598ede25f14feb0143bd50e08df9f9795099
	scene->addChild(mHpBar);

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setScale(3);
<<<<<<< HEAD
	mloadingHpBar->setPosition(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width / 4, 480));
=======
	mloadingHpBar->setPosition(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width / 4, 400));
>>>>>>> 6a81598ede25f14feb0143bd50e08df9f9795099
	scene->addChild(mloadingHpBar);
	init();
}


Castle::~Castle()
{
}

void Castle::update()
{
}
void Castle::init()
{
	mloadingHpBar->setPercent(100);
}

void Castle::setPosHp(cocos2d::Vec2 pos)
{
}





