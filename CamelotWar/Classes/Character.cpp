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
	mHP = mHP - hp;
}

void Character::init()
{

}


void Character::reBorn(Character * member)
{
	member->setPos(cocos2d::Vec2(member->getPos().x, SCREEN_H / 3));
	member->mloadingHpBar->setPercent(100);
	member->mAlive = true;
}

void Character::setPosAll(cocos2d::Vec2 pos)
{
	setPos(pos);
	setPosHp(cocos2d::Vec2(pos.x, pos.y + mSprite->getContentSize().height / 2));
}



int Character::getHP()
{
	return mHP;
}

void Character::setHP(int hp)
{
	mHP = hp;
}

void Character::init()
{
	mHpBar = cocos2d::Sprite::create("loading_bg.png");

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mloadingHpBar->setPercent(100);

	
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

