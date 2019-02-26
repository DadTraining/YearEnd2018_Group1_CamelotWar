#include "Archer_Fire.h"
#include "Defines.h"
#include "Character.h"

Archer_Fire::Archer_Fire()
{
}

Archer_Fire::~Archer_Fire()
{
}

Archer_Fire::Archer_Fire(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER_FIRE);
	//setPos(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	scene->addChild(mSprite);
	
	mSprite->setFlipX(false);

	for (int i = 0; i < 10; i++) {
		auto fire = new Fire(scene);
		//fire->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
		fires.push_back(fire);
		fire->setVisible(false);
	}
	init();
}

void Archer_Fire::walk()
{
}

void Archer_Fire::attack()
{
}

void Archer_Fire::die()
{
}

void Archer_Fire::setListPedestal(std::vector<Pedestal*> listPedestals)
{
	mListPedestals = listPedestals;
}

void Archer_Fire::flip(bool flip)
{
	mSprite->setFlipX(flip);
}

void Archer_Fire::turnOnFire(cocos2d::Vec2 pos)
{
	mFrameCount++;
	int a = (COUNT_IMG_ARCHER_ATTACK * FPS) / mSpeed;
	if (mFrameCount % a == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (fires[i]->isVisible() == false)
			{
				if (mSprite->isFlipX() == false)
				{
					fires[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width / 2, getPos().y));
				}
				else
				{
					fires[i]->setPos(cocos2d::Vec2(getPos().x - mSprite->getContentSize().width / 2, getPos().y));
				}
				fires[i]->setVisible(true);
				fires[i]->setMShoot(mSprite->isFlipX());
				fires[i]->fly(pos);
				break;
			}
		}
	}
}

void Archer_Fire::shootFire()
{
	for (int i = 0; i < 10; i++)
	{
		if (fires[i]->isVisible() == true)
		{
			fires[i]->update();
		}
	}
}

void Archer_Fire::collision()
{
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		for (int j = 0; j < fires.size(); j++)
		{
			if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(fires[j]->getSprite()->getBoundingBox()))
			{
				mListMonsters[i]->deCreaseHP(100);
				fires[j]->setVisible(false);
				fires[j]->setPos(cocos2d::Vec2(getPos().x, getPos().y));
			}
		}
	}
}

void Archer_Fire::reuseFire()
{
	for (int i = 0; i < 10; i++)
	{
		if (fires[i]->getPos().y <= SCREEN_H / 3)
		{
			fires[i]->setVisible(false);
		}
	}
}

void Archer_Fire::setListMonster(std::vector<Character*> &listMonsters)
{
	for (int i = 0; i < listMonsters.size(); i++)
	{
		mListMonsters.push_back(listMonsters[i]);
	}
}

void Archer_Fire::update()
{
	for (int j = 0; j < mListMonsters.size(); j++)
	{
		if (mListMonsters[j]->getAlive() == 1)
		{
			if (mListMonsters[j]->getPos().x >= getPos().x - mRange && mListMonsters[j]->getPos().x <= getPos().x)
			{
				mSprite->setFlipX(true);
				turnOnFire(mListMonsters[j]->getPos());
				if (changeStatus == 0)
				{
					setAnimation(NAME_PLIST_ARCHER_ATTACK_FIRE, NAME_PNG_ARCHER_ATTACK_FIRE, COUNT_IMG_ARCHER_ATTACK_FIRE, mSpeed, 0);
					changeStatus = 1;
				}
				break;
			}
			else if (mListMonsters[j]->getPos().x >= getPos().x  && mListMonsters[j]->getPos().x <= getPos().x + mRange)
			{
				mSprite->setFlipX(false);
				turnOnFire(mListMonsters[j]->getPos());
				if (changeStatus == 0)
				{
					setAnimation(NAME_PLIST_ARCHER_ATTACK_FIRE, NAME_PNG_ARCHER_ATTACK_FIRE, COUNT_IMG_ARCHER_ATTACK_FIRE, mSpeed, 0);
					changeStatus = 1;
				}
				break;
			}
			else
			{
				mSprite->stopAllActions();
				changeStatus = 0;
			}
		}
		else if (j == mListMonsters.size() - 1)
		{
			mSprite->stopAllActions();
			changeStatus = 0;
		}
	}

	reuseFire();
	shootFire();
	collision();
	collisionWithPedestal();
	setPosAll(getPos());
}

void Archer_Fire::init()
{
	mFrameCount = 0;
	mSpeed = 5;
	mRange = 300;
	changeStatus = 0;
	hasAnimated = false;
	
}

void Archer_Fire::collisionWithPedestal()
{
	for (int i = 0; i < mListPedestals.size(); i++)
	{
		if (mListPedestals[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()))
		{
			mAppear = true;
			mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
			setPos(cocos2d::Vec2(getPos().x, mListPedestals[i]->getPos().y + mListPedestals[i]->getSprite()->getContentSize().height / 2 - 10));
			break;
		}
	}
	if (!mAppear)
	{
		setAlive(2);
	}
}
