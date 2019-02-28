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

	setPos(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width/4, 330));

	scene->addChild(mSprite);

	mHpBar = cocos2d::Sprite::create("loading_bg.png");
	mHpBar->setScale(3);

	mHpBar->setPosition(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width / 4, 480));

	scene->addChild(mHpBar);

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setScale(3);

	mloadingHpBar->setPosition(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width / 4, 480));

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
	mHP = 10000;
}

void Castle::setPosHp(cocos2d::Vec2 pos)
{
}

void Castle::deCreaseHP(int hp)
{
	float percentHpDecrease = ((float)hp / (float)mHP) * 100;
	mloadingHpBar->setPercent(mloadingHpBar->getPercent() - percentHpDecrease);
	mHP = mHP - hp;
}





