#include "AxeKnight.h"
#include "Defines.h"


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
	/*if (mSprite->getBoundingBox().intersectsRect(mCastle->getSprite()->getBoundingBox()))
	{
		mCheckAtk = true;
	}*/
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()))
		{
			mCheckAtk = true;
			break;
		}
		else
		{
			mCheckAtk = false;
			break;
		}
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
			mListMonsters[i]->deCreaseHP(100);
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
		changeStatus += 2;
	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_AXEKNIGHT_DIE, NAME_PNG_AXEKNIGHT_DIE, COUNT_IMG_AXEKNIGHT_DIE, mSpeed, 1);
		changeStatus += 1;
	}
	setPos(getPos() - cocos2d::Vec2(0, 1));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

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
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height + 10));
}

void AxeKnight::init()
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
	mSprite->setPosition(cocos2d::Vec2(SCREEN_W + 50, SCREEN_H / 3 - 50));
}

