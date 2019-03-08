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
	this->addPhysicsBody();

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
	setPos(mSprite->getPosition() + cocos2d::Vec2((float)mSpeed / (float)10, 0));
	countFrame = 0;
}

void HammerOrk::attack()
{
	countFrame = countFrame + 1;
	if (changeStatus == 0)
	{
		changeStatus = 1;
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
		mCastle->deCreaseHP(mDamage);
		countFrame = 0;
	}
}

void HammerOrk::die()
{
	mAlive = 0;
	if (changeStatus == 1)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERORK_DIE, NAME_PNG_HAMMERORK_DIE, COUNT_IMG_HAMMERORK_DIE, mSpeed, 1);
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_HERO_DIED, false, 1.0f, 1.0f, 1.0f);
		changeStatus += 2;

		if (getPos().x < 100)
		{
			for (int i = 0; i < getCoin().size(); i++)
			{
				if (!getCoin().at(i)->getCheckFall())
				{
					setVisibleCoin(true, i);
					getCoin().at(i)->setPos(getPos());
					getCoin().at(i)->PushCoin(cocos2d::Vec2(150, 500));
					getCoin().at(i)->setDynamic(true);
					getCoin().at(i)->setCheckFall(true);
					break;
				}
			}
		}
		else
		{
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

	}
	if (changeStatus == 2)
	{
		mSprite->stopAllActions();
		setAnimation(NAME_PLIST_HAMMERORK_DIE, NAME_PNG_HAMMERORK_DIE, COUNT_IMG_HAMMERORK_DIE, mSpeed, 1);
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_HERO_DIED, false, 1.0f, 1.0f, 1.0f);
		changeStatus += 1;

		if (getPos().x < 100)
		{
			for (int i = 0; i < getCoin().size(); i++)
			{
				if (!getCoin().at(i)->getCheckFall())
				{
					setVisibleCoin(true, i);
					getCoin().at(i)->setPos(getPos());
					getCoin().at(i)->PushCoin(cocos2d::Vec2(150, 500));
					getCoin().at(i)->setDynamic(true);
					getCoin().at(i)->setCheckFall(true);
					break;
				}
			}
		}
		else
		{
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

	}
	
	mPhysicsBody->setDynamic(true);

	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void HammerOrk::collision()
{
	if (mSprite->getBoundingBox().intersectsRect(mCastle->getSprite()->getBoundingBox()))
	{
		mCheckAtk = true;
	}
}

void HammerOrk::setListMonster(std::vector<Character*> listMonsters)
{
}

void HammerOrk::update()
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

void HammerOrk::init()
{
	mSpeed = 15;
	mHP = 380;
	mDamage = 80;
	mPrice = 15;
	
	mAlive = 1;
	changeStatus = 0;
	mAppear = false;

	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
}