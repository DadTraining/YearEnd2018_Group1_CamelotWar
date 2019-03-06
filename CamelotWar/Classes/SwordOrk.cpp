#include "SwordOrk.h"
#include "Defines.h"

SwordOrk::SwordOrk()
{
}

SwordOrk::~SwordOrk()
{
}

SwordOrk::SwordOrk(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_SWORDORK);
	this->addPhysicsBody();

	scene->addChild(mSprite);
	init();
}

void SwordOrk::walk()
{
	if (changeStatus == 0)
	{
		setAnimation(NAME_PLIST_SWORDORK_WALK, NAME_PNG_SWORDORK_WALK, COUNT_IMG_SWORDORK_WALK, mSpeed, 0);
		changeStatus += 1;
	}
	setPos(mSprite->getPosition() + cocos2d::Vec2((float)mSpeed /(float) 10, 0));
	countFrame = 0;
}

void SwordOrk::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus = 1;
	}
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_SWORDORK_ATK, NAME_PNG_SWORDORK_ATK, COUNT_IMG_SWORDORK_ATK, mSpeed, 0);
		changeStatus++;
	}
	int a = (COUNT_IMG_SWORDORK_ATK * FPS) / mSpeed;
	if (countFrame % a == 0)
	{
		mCastle->deCreaseHP(mDamage);
		countFrame = 0;
	}
}

void SwordOrk::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_SWORDORK_DIE, NAME_PNG_SWORDORK_DIE, COUNT_IMG_SWORDORK_DIE, mSpeed, 1);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_HERO_DIED, false, 1.0f, 1.0f, 1.0f);
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
		setAnimation(NAME_PLIST_SWORDORK_DIE, NAME_PNG_SWORDORK_DIE, COUNT_IMG_SWORDORK_DIE, mSpeed, 1);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_HERO_DIED, false, 1.0f, 1.0f, 1.0f);
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

void SwordOrk::collision()
{
	if (mSprite->getBoundingBox().intersectsRect(mCastle->getSprite()->getBoundingBox()))
	{
		mCheckAtk = true;
	}
}

void SwordOrk::setListMonster(std::vector<Character*> listMonsters)
{
}

void SwordOrk::update()
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

	if (getPos().y < -1000)
	{
		mPhysicsBody->setDynamic(false);
		checkFallDone = true;
	}
}

void SwordOrk::init()
{
	mSpeed = 20;
	mHP = 500;
	mDamage = 120;
	mPrice = 30;
	
	mAlive = 1;
	changeStatus = 0;
	mAppear = false;

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
}
