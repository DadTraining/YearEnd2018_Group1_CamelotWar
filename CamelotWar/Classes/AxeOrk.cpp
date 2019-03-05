#include "AxeOrk.h"
#include "Defines.h"

AxeOrk::AxeOrk()
{
}

AxeOrk::~AxeOrk()
{
}

AxeOrk::AxeOrk(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_AXEORK);
	scene->addChild(mSprite);

	init();
}

void AxeOrk::walk()
{
	if (changeStatus == 0)
	{
		setAnimation(NAME_PLIST_AXEORK_WALK, NAME_PNG_AXEORK_WALK, COUNT_IMG_AXEORK_WALK, mSpeed, 0);
		changeStatus += 1;
	}
	setPos(mSprite->getPosition() + cocos2d::Vec2(mSpeed / 10, 0));
	countFrame = 0;
}

void AxeOrk::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus++;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEORK_ATK, NAME_PNG_AXEORK_ATK, COUNT_IMG_AXEORK_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_AXEORK_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		mCastle->deCreaseHP(100);
		countFrame = 0;
	}
}

void AxeOrk::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEORK_DIE, NAME_PNG_AXEORK_DIE, COUNT_IMG_AXEORK_DIE, mSpeed, 1);
		changeStatus += 2;
	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEORK_DIE, NAME_PNG_AXEORK_DIE, COUNT_IMG_AXEORK_DIE, mSpeed, 1);
		changeStatus += 1;
	}
	setPos(getPos() - cocos2d::Vec2(0, 1));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void AxeOrk::collision()
{
	if (mSprite->getBoundingBox().intersectsRect(mCastle->getSprite()->getBoundingBox()))
	{
		mCheckAtk = true;
	}
}

void AxeOrk::update()
{
	if (mCheckAtk && mAlive == 1)
	{
		attack();
	}
	if (!mCheckAtk && mAlive == 1)
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
	collision();
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height + 10));
}

void AxeOrk::init()
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
}