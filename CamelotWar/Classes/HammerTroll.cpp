#include "HammerTroll.h"
#include "Defines.h"


HammerTroll::HammerTroll()
{
}


HammerTroll::~HammerTroll()
{
}

HammerTroll::HammerTroll(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_HAMMERTROLL);
	scene->addChild(mSprite);

	init();
}

void HammerTroll::walk()
{
	setPos(mSprite->getPosition() + cocos2d::Vec2(mSpeed / 10, 0));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void HammerTroll::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERTROLL_ATK, NAME_PNG_HAMMERTROLL_ATK, COUNT_IMG_HAMMERTROLL_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_HAMMERTROLL_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		deCreaseHP(100);
	}
}

void HammerTroll::die()
{
	mAlive = 0;
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERTROLL_DIE, NAME_PNG_HAMMERTROLL_DIE, COUNT_IMG_HAMMERTROLL_DIE, mSpeed, 1);
		changeStatus += 2;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERTROLL_DIE, NAME_PNG_HAMMERTROLL_DIE, COUNT_IMG_HAMMERTROLL_DIE, mSpeed, 1);
		changeStatus += 1;
	}
	setPos(getPos() - cocos2d::Vec2(0, 1));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

}

void HammerTroll::update()
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

void HammerTroll::init()
{
	changeStatus = 0;
	mSpeed = 20;
	mAlive = 1;
	mHP = 1000;
	mPrice = 100;
	mDamage = 100;
	mRange = 10;
	

	setPos(cocos2d::Vec2(MONSTER_APPEAR, SCREEN_H / 3));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	setAnimation(NAME_PLIST_HAMMERTROLL_WALK, NAME_PNG_HAMMERTROLL_WALK, COUNT_IMG_HAMMERTROLL_WALK, mSpeed, 0);
}