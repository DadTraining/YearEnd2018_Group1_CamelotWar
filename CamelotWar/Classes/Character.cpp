#include "Model.h"
#include "Character.h"

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
	mHP = mHP - hp;

}

void Character::setPosAll(cocos2d::Vec2 pos)
{
	setPos(pos);
	setPosHp(cocos2d::Vec2(pos.x, pos.y + mSprite->getContentSize().height + 10));
} 

void Character::reBorn()
{

}

void Character::init()
{
	mHpBar = cocos2d::Sprite::create("loading_bg.png");

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mloadingHpBar->setPercent(100);

	mAppear = false;
	
}

void Character::setAlive(int alive)
{
	mAlive = alive;
}

int Character::getAlive()
{
	return mAlive;
}

void Character::setAppear(bool appear)
{
	mAppear = appear;
}

bool Character::getAppear()
{
	return mAppear;
}

void Character::setPosHp(cocos2d::Vec2 pos)
{
	mHpBar->setPosition(pos);
	mloadingHpBar->setPosition(pos);
}

