#include "SwordKnight.h"
#include "Defines.h"


SwordKnight::SwordKnight()
{
}


SwordKnight::~SwordKnight()
{
}

SwordKnight::SwordKnight(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_SWORDKNIGHT);
	mSprite->setFlipX(true);
	scene->addChild(mSprite);
	init();
}

void SwordKnight::walk()
{
	if (changeStatus == 2)
	{
		changeStatus = 0;
	}
	if (changeStatus == 0)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_SWORDKNIGHT_WALK, NAME_PNG_SWORDKNIGHT_WALK, COUNT_IMG_SWORDKNIGHT_WALK, mSpeed, 0);
		changeStatus += 1;
	}
	setPos(mSprite->getPosition() - cocos2d::Vec2(mSpeed / 10, 0));
	countFrame = 0;
}

void SwordKnight::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus = 1;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_SWORDKNIGHT_ATK, NAME_PNG_SWORDKNIGHT_ATK, COUNT_IMG_SWORDKNIGHT_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_SWORDKNIGHT_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		for (int i = 0; i < mListMonsters.size(); i++)
		{
			if (mListMonsters[i]->getAlive())
			{
				mListMonsters[i]->deCreaseHP(100);
				break;
			}
		}
		countFrame = 0;
	}
}

void SwordKnight::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_SWORDKNIGHT_DIE, NAME_PNG_SWORDKNIGHT_DIE, COUNT_IMG_SWORDKNIGHT_DIE, mSpeed, 1);
		changeStatus += 2;
	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_SWORDKNIGHT_DIE, NAME_PNG_SWORDKNIGHT_DIE, COUNT_IMG_SWORDKNIGHT_DIE, mSpeed, 1);
		changeStatus += 1;
	}
	setPos(getPos() - cocos2d::Vec2(0, 1));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

}

void SwordKnight::setListMonster(std::vector<Character*> listMonsters)
{
	mListMonsters = listMonsters;
}

void SwordKnight::collision()
{
	bool check = false;
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()) &&
			mListMonsters[i]->getAlive() == 1)
		{
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

void SwordKnight::update()
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

void SwordKnight::init()
{
	changeStatus = 0;
	mSpeed = 15;
	mAlive = 1;
	mHP = 10000;
	mPrice = 100;
	mDamage = 500;
	mRange = 10;
	mAppear = false;

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
	mSprite->setPosition(cocos2d::Vec2(SCREEN_W + 50, SCREEN_H / 3 - 50));

}
