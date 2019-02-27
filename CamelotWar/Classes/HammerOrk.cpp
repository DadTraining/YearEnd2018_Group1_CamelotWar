#include "HammerOrk.h"
#include "Defines.h"


HammerOrk::HammerOrk()
{
}


HammerOrk::~HammerOrk()
{
}

HammerOrk::HammerOrk(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_HAMMERORK);
	scene->addChild(mSprite);

	init();
}

void HammerOrk::walk()
{
	if (changeStatus == 0)
	{
		setAnimation(NAME_PLIST_HAMMERORK_WALK, NAME_PNG_HAMMERORK_WALK, COUNT_IMG_HAMMERORK_WALK, mSpeed, 0);
		changeStatus += 1;
	}
	setPos(mSprite->getPosition() + cocos2d::Vec2(mSpeed / 10, 0));
	countFrame = 0;
}

void HammerOrk::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus++;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERORK_ATK, NAME_PNG_HAMMERORK_ATK, COUNT_IMG_HAMMERORK_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_HAMMERORK_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		//deCreaseHP(100);
	}
}

void HammerOrk::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERORK_DIE, NAME_PNG_HAMMERORK_DIE, COUNT_IMG_HAMMERORK_DIE, mSpeed, 1);
		changeStatus += 2;
	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERORK_DIE, NAME_PNG_HAMMERORK_DIE, COUNT_IMG_HAMMERORK_DIE, mSpeed, 1);
		changeStatus += 1;
	}
	setPos(getPos() - cocos2d::Vec2(0, 1));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void HammerOrk::update()
{
	if (getPos().x >= SCREEN_W - 100 && mAlive == 1)
	{
		attack();
	}
	if (getPos().x < SCREEN_W - 100 && mAlive == 1)
	{
		walk();
		countFrame = 0;
	}
	if (mloadingHpBar->getPercent() == 0)
	{
		die();
	}
	if (changeStatus == 3)
	{
		changeStatus = 0;
	}
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height + 10));
}

void HammerOrk::init()
{
	changeStatus = 0;
	mSpeed = 15;
	mAlive = 1;
	mHP = 1000;
	mPrice = 100;
	mDamage = 100;
	mRange = 10;
	mAppear = false;

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
	setPos(cocos2d::Vec2(MONSTER_APPEAR, SCREEN_H / 3 - 30));
}