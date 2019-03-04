#include "Castle.h"
#include "Character.h"
#include "Defines.h"

Castle::Castle()
{
}

Castle::Castle(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create("tower.png");

	setPos(cocos2d::Vec2(SCREEN_W - mSprite->getContentSize().width/4 - 25, 255));

	scene->addChild(mSprite,9999);

	mHpBar = cocos2d::Sprite::create("loading1.png");
	mHpBar->setAnchorPoint(cocos2d::Vec2(0, 1));
	mHpBar->setPosition(cocos2d::Vec2(0, SCREEN_H+1));

	scene->addChild(mHpBar);

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loading2.png");
	mloadingHpBar->setAnchorPoint(cocos2d::Vec2(0, 1));
	mloadingHpBar->setPosition(cocos2d::Vec2(80, SCREEN_H-8));

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

cocos2d::ui::LoadingBar * Castle::getLoadingbar()
{
	return mloadingHpBar;
}