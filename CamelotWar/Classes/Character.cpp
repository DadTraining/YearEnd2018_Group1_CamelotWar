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

void Character::update()
{
}

void Character::init()
{
	setHpBar(cocos2d::Sprite::create("loading_bg.png"));

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mloadingHpBar->setPercent(100);
}

void Character::deCreaseHP()
{

}

void Character::reBorn()
{

}

int Character::getHP()
{
	return mHP;
}

void Character::setHP(int hp)
{
	mHP = hp;
}

int Character::getPrice()
{
	return mPrice;
}

void Character::setPrice(int price)
{
	mPrice = price;
}

int Character::getDamage()
{
	return mDamage;
}

void Character::setDamage(int damage)
{
	mDamage = damage;
}

int Character::getSpeed()
{
	return mSpeed;
}

void Character::setSpeed(int speed)
{
	mSpeed = speed;
}

int Character::getRange()
{
	return mRange;
}

void Character::setRange(int range)
{
	mRange = range;
}

cocos2d::Sprite * Character::getHpBar()
{
	return mHpBar;
}

void Character::setHpBar(cocos2d::Sprite * hpBar)
{
	mHpBar = hpBar;
}

void Character::deCreaseHpBar()
{
}
