#include "BoneTroll.h"
#include "Defines.h"


BoneTroll::BoneTroll()
{
}


BoneTroll::~BoneTroll()
{
}

BoneTroll::BoneTroll(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_BONETROLL);
	scene->addChild(mSprite);

	init();
}

void BoneTroll::walk()
{
	setPos(mSprite->getPosition() + cocos2d::Vec2(mSpeed / 10, 0));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void BoneTroll::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_BONETROLL_ATK, NAME_PNG_BONETROLL_ATK, COUNT_IMG_BONETROLL_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_BONETROLL_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		deCreaseHP(100);
	}
}

void BoneTroll::die()
{
	mAlive = 0;
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_BONETROLL_DIE, NAME_PNG_BONETROLL_DIE, COUNT_IMG_BONETROLL_DIE, mSpeed, 1);
		changeStatus += 2;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_BONETROLL_DIE, NAME_PNG_BONETROLL_DIE, COUNT_IMG_BONETROLL_DIE, mSpeed, 1);
		changeStatus += 1;
	}
	setPos(getPos() - cocos2d::Vec2(0, 1));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

}

void BoneTroll::update()
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

void BoneTroll::init()
{
	changeStatus = 0;
	mSpeed = 15;
	mAlive = 1;
	mHP = 1000;
	mPrice = 100;
	mDamage = 100;
	mRange = 10;
	setPos(cocos2d::Vec2(MONSTER_APPEAR, SCREEN_H /2));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	setAnimation(NAME_PLIST_BONETROLL_WALK, NAME_PNG_BONETROLL_WALK, COUNT_IMG_BONETROLL_WALK, mSpeed, 0);
}