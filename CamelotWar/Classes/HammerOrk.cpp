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
	setPos(mSprite->getPosition() + cocos2d::Vec2(mSpeed / 10, 0));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void HammerOrk::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
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
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERORK_DIE, NAME_PNG_HAMMERORK_DIE, COUNT_IMG_HAMMERORK_DIE, mSpeed, 1);
		changeStatus += 2;
	}
	if (changeStatus == 1)
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
	if (getPos().x >= SCREEN_W / 2 && mAlive == 1)
	{
		attack();
	}
	if (getPos().x < SCREEN_W / 2 && mAlive == 1)
	{
		walk();
	}
	if (mloadingHpBar->getPercent() == 0)
	{
		die();
	}
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

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	setAnimation(NAME_PLIST_HAMMERORK_WALK, NAME_PNG_HAMMERORK_WALK, COUNT_IMG_HAMMERORK_WALK, mSpeed, 0);
}