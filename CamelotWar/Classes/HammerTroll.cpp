#include "HammerTroll.h"
#include "Defines.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
HammerTroll::HammerTroll()
{
}

HammerTroll::~HammerTroll()
{
}

HammerTroll::HammerTroll(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_HAMMERTROLL);
	this->addPhysicsBody();

	scene->addChild(mSprite);
	init();
}

void HammerTroll::walk()
{
	if (changeStatus == 0)
	{
		setAnimation(NAME_PLIST_HAMMERTROLL_WALK, NAME_PNG_HAMMERTROLL_WALK, COUNT_IMG_HAMMERTROLL_WALK, mSpeed, 0);
		changeStatus += 1;
	}
	setPos(mSprite->getPosition() + cocos2d::Vec2(mSpeed / 10, 0));
	countFrame = 0;
}

void HammerTroll::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus = 1;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERTROLL_ATK, NAME_PNG_HAMMERTROLL_ATK, COUNT_IMG_HAMMERTROLL_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_HAMMERTROLL_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		mCastle->deCreaseHP(100);
		countFrame = 0;
	}
}

void HammerTroll::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERTROLL_DIE, NAME_PNG_HAMMERTROLL_DIE, COUNT_IMG_HAMMERTROLL_DIE, mSpeed, 1);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_MONSTER_DIED, false, 1.0f, 1.0f, 1.0f);
		changeStatus += 2;

		for (int i = 0; i < getCoin().size(); i++)
		{
			if (!getCoin().at(i)->getCheckFall())
			{
				setVisibleCoin(true, i);
				getCoin().at(i)->setPos(getPos());
				getCoin().at(i)->PushCoin(cocos2d::Vec2(-100, 500));
				getCoin().at(i)->setDynamic(true);
				getCoin().at(i)->setCheckFall(true);
				break;
			}
		}
	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERTROLL_DIE, NAME_PNG_HAMMERTROLL_DIE, COUNT_IMG_HAMMERTROLL_DIE, mSpeed, 1);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_MONSTER_DIED, false, 1.0f, 1.0f, 1.0f);
		changeStatus += 1;

		for (int i = 0; i < getCoin().size(); i++)
		{
			if (!getCoin().at(i)->getCheckFall())
			{
				setVisibleCoin(true, i);
				getCoin().at(i)->setPos(getPos());
				getCoin().at(i)->PushCoin(cocos2d::Vec2(-100, 500));
				getCoin().at(i)->setDynamic(true);
				getCoin().at(i)->setCheckFall(true);
				break;
			}
		}
	}
	
	mPhysicsBody->setDynamic(true);

	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

}

void HammerTroll::collision()
{
	if (mSprite->getBoundingBox().intersectsRect(mCastle->getSprite()->getBoundingBox()))
	{
		mCheckAtk = true;
	}
}

void HammerTroll::update()
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

void HammerTroll::init()
{
	changeStatus = 0;
	mSpeed = 20;
	mAlive = 1;
	mHP = 1000;
	mPrice = 100;
	mDamage = 100;
	mRange = 10;
	mAppear = false;

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
}