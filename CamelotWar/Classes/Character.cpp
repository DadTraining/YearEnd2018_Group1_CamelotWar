#include "Model.h"
#include "Character.h"
#include "Defines.h"

Character::Character()
{

}

Character::~Character()
{

}

Character::Character(cocos2d::Scene * scene)
{
	init();
	scene->addChild(mHpBar);
	scene->addChild(mloadingHpBar);
}

void Character::deCreaseHP(int hp)
{
	float percentHpDecrease =( (float) hp / (float)mHP) * 100;
	mloadingHpBar->setPercent(mloadingHpBar->getPercent() - percentHpDecrease);
}

void Character::reBorn()
{
	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
	setPos(cocos2d::Vec2(getPos().x, SCREEN_H / 3 - mSprite->getContentSize().height));
	mloadingHpBar->setPercent(100);
	mAlive = 1;

}

void Character::setPosAll(cocos2d::Vec2 pos)
{
	setPos(pos);
	setPosHp(cocos2d::Vec2(pos.x, pos.y + mSprite->getContentSize().height + 10));
} 

void Character::init()
{
	mHpBar = cocos2d::Sprite::create("loading_bg.png");

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mloadingHpBar->setPercent(100);

	setVisibleHP(false);

	mAppear = false;
	mCheckAtk = false;

}

void Character::setVisibleHP(bool visible)
{
	mHpBar->setVisible(visible);
	mloadingHpBar->setVisible(visible);
}

void Character::setAlive(int alive)
{
	mAlive = alive;
}

int Character::getAlive()
{
	return mAlive;
}

void Character::setCastle(Castle * castle)
{
	mCastle = castle;
}

void Character::setAppear(bool appear)
{
	mAppear = appear;
}

bool Character::getAppear()
{
	return mAppear;
}

void Character::setcheckAppear(bool appear)
{
	checkAppear = appear;
	
}

bool Character::getcheckAppear()
{
	return checkAppear;
}

void Character::setPosHp(cocos2d::Vec2 pos)
{
	mHpBar->setPosition(pos);
	mloadingHpBar->setPosition(pos);
}

