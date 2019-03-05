#include "AxeKnight.h"
#include "Defines.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
AxeKnight::AxeKnight()
{
}


AxeKnight::~AxeKnight()
{
}

AxeKnight::AxeKnight(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_AXEKNIGHT);
	mSprite->setFlipX(true);
	scene->addChild(mSprite);
	init();
}

void AxeKnight::walk()
{
	if (changeStatus == 2)
	{
		changeStatus = 0;
	}
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEKNIGHT_WALK, NAME_PNG_AXEKNIGHT_WALK, COUNT_IMG_AXEKNIGHT_WALK, mSpeed, 0);
		changeStatus += 1;
	}
	setPos(mSprite->getPosition() - cocos2d::Vec2(mSpeed / 10, 0));
	countFrame = 0;
}

void AxeKnight::collision()
{
	bool check = false;
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()) &&
			mListMonsters[i]->getAlive() == 1)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_STABBE, false, 1.0f, 1.0f, 1.0f);
			mCheckAtk = true;
			check = true;
			break;
		}
	}
	if (!check)
	{
		mCheckAtk = false;
	}
}

void AxeKnight::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus = 1;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEKNIGHT_ATK, NAME_PNG_AXEKNIGHT_ATK, COUNT_IMG_AXEKNIGHT_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_AXEKNIGHT_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		for (int i = 0; i < mListMonsters.size(); i++)
		{
			if (mListMonsters[i]->getAlive())
			{
				mListMonsters[i]->deCreaseHP(mDamage);
				break;
			}
		}
		countFrame = 0;
	}
}

void AxeKnight::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEKNIGHT_DIE, NAME_PNG_AXEKNIGHT_DIE, COUNT_IMG_AXEKNIGHT_DIE, mSpeed, 1);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_HERO_DIED, false, 1.0f, 1.0f, 1.0f);
		changeStatus += 2;
	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEKNIGHT_DIE, NAME_PNG_AXEKNIGHT_DIE, COUNT_IMG_AXEKNIGHT_DIE, mSpeed, 1);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_HERO_DIED, false, 1.0f, 1.0f, 1.0f);
		changeStatus += 1;
	}
	

}

void AxeKnight::setListMonster(std::vector< Character*> listMonsters)
{
	mListMonsters = listMonsters;
}

void AxeKnight::update()
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
	deCreaseHP(1);
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height + 10));
}

void AxeKnight::init()
{
	changeStatus = 0;
	mSpeed = 10;
	mAlive = 1;
	mHP = 750;
	mPrice = 150;
	mDamage = 20;
	mRange = 10;
	mAppear = false;

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
	mSprite->setPosition(cocos2d::Vec2(SCREEN_W , SCREEN_H / 3 - 70));
}

