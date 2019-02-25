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
	setPos(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	scene->addChild(mSprite);
	
	mSprite->setFlipX(false);

	for (int i = 0; i < 10; i++) {
		auto fire = new Fire(scene);
		fire->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
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

void Archer_Fire::flip(boolean flip)
{
	mSprite->setFlippedX(flip);
}

void Archer_Fire::turnOnFire(cocos2d::Vec2 pos)
{
	mFrameCount++;
	//int a = (COUNT_IMG_ARCHER_ATTACK_FIRE *FPS) / mSpeed;
	if (mFrameCount == 40)
	{
		mFrameCount = 0;
		for (int i = 0; i < 10; i++)
		{
			if (!fires[i]->isVisible())
			{
				/*if (mSprite->isFlipX() == false)
				{
					fires[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
				}
				else
				{
					fires[i]->setPos(cocos2d::Vec2(getPos().x - mSprite->getContentSize().width, getPos().y));
				}*/
				fires[i]->setPos(cocos2d::Vec2(getPos().x - mSprite->getContentSize().width, getPos().y));
				fires[i]->setVisible(true);
				fires[i]->setMFire(mSprite->isFlipX());
				fires[i]->fly(pos);
				break;
			}
		}
	}
}

void Archer_Fire::fireFire()
{
	for (int i = 0; i < 10; i++)
	{
		if (fires[i]->isVisible() == true)
		{
			fires[i]->update();
		}
	}
}

void Archer_Fire::collsion()
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
		if (fires[i]->getPos().y <= mListMonsters[0]->getPos().y && fires[i]->isVisible())
		{
			fires[i]->setVisible(false);
			fires[i]->setPos(cocos2d::Vec2(getPos().x, getPos().y));
		}
	}
}

void Archer_Fire::setListMonster(std::vector<Character*> &listMonsters)
{
	mListMonsters = listMonsters;
}

void Archer_Fire::update()
{
	//for (int j = 0; j < mListMonsters.size(); j++)
	//{
	//	//if (mListMonsters[j]->getPos().x >= getPos().x - mRange && mListMonsters[j]->getPos().x <= getPos().x && mListMonsters[j]->getAlive() == 1)
	//	//{
	//	//	mSprite->setFlipX(true);
	//	//	turnOnFire(mListMonsters[j]->getPos());
	//	//	break;
	//	//}
	//	//else if (mListMonsters[j]->getPos().x >= getPos().x  && mListMonsters[j]->getPos().x <= getPos().x + mRange && mListMonsters[j]->getAlive() == 1)
	//	//{
	//	//	mSprite->setFlipX(false);
	//	//	turnOnFire(mListMonsters[j]->getPos());
	//	//	break;
	//	//}
	//	if (mListMonsters.at(j)->getPos().x >= getPos().x - mRange && mListMonsters[j]->getPos().x <= getPos().x)
	//	{
	//		if (mListMonsters[j]->getAlive() == 1)
	//		{
	//			mSprite->setFlipX(false);
	//			turnOnFire(mListMonsters[j]->getPos());
	//			break;
	//		}
	//	}
	//}
	//fireFire();
	//collsion();
	//setPosAll(getPos());

	for (int i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters.at(i)->getAlive() == 1)
		{
			if (mListMonsters.at(i)->getPos().x >= getPos().x - mRange && mListMonsters[i]->getPos().x <= getPos().x +mRange)
			{
				turnOnFire(mListMonsters[i]->getPos());
				break;
			}
		}
	}

	//reuseFire();
	fireFire();
	collsion();
	setPosAll(getPos());
}

void Archer_Fire::init()
{
	mFrameCount = 0;
	mSpeed = 7;
	mRange = 300;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	//setAnimation(NAME_PLIST_ARCHER_ATTACK_FIRE, NAME_PNG_ARCHER_ATTACK_FIRE, COUNT_IMG_ARCHER_ATTACK_FIRE, mSpeed, 0);

}
