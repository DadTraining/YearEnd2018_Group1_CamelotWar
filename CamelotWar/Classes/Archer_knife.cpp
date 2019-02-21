#include "Archer_knife.h"
#include "Defines.h"
#include "Character.h"



Archer_knife::Archer_knife()
{
}


Archer_knife::~Archer_knife()
{
}

Archer_knife::Archer_knife(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER_KNIFE);
	setPos(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H -200));
	scene->addChild(mSprite);
	mSprite->setFlipX(false);


	for (int i = 0; i < 10; i++)
	{
		auto knife = new Knife(scene);
		knife->setPos(cocos2d::Vec2(getPos().x, getPos().y));
		knifes.push_back(knife);
		knife->setVisible(false);
	}
	init();
}

void Archer_knife::walk()
{
}

void Archer_knife::attack()
{
}

void Archer_knife::die()
{
}

void Archer_knife::flip(boolean flip)
{
	mSprite->setFlipX(flip);
}

void Archer_knife::turnOnKnife(cocos2d::Vec2 pos)
{
	mFrameCount++;
	int a = (COUNT_IMG_ARCHER_ATTACK_KNIFE * FPS) / mSpeed;
	if (mFrameCount % a == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (knifes[i]->isVisible() == false)
			{
				if (mSprite->isFlipX() == false)
				{
					knifes[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
				}
				else
				{
					knifes[i]->setPos(cocos2d::Vec2(getPos().x - mSprite->getContentSize().width, getPos().y));
				}
				knifes[i]->setVisible(true);
				knifes[i]->setMKnife(mSprite->isFlipX());
				knifes[i]->fly(pos);
				break;
			}
		}
	}
}

void Archer_knife::shootKnife()
{
	for (int i = 0; i < 10; i++)
	{
		if (knifes[i]->isVisible() == true)
		{
			knifes[i]->update();

		}
	}
}

void Archer_knife::collision()
{
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		for (int j = 0; j < knifes.size(); j++)
		{
			if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(knifes[j]->getSprite()->getBoundingBox()))
			{
				mListMonsters[i]->deCreaseHP(100);
				knifes[i]->setVisible(false);
				knifes[j]->setPos(cocos2d::Vec2(getPos().x, getPos().y));
			}
		}
	}
}

void Archer_knife::reuseKnife()
{
	for (int i = 0; i < 10; i++)
	{
		if (knifes[i]->getPos().y <= mListMonsters[0]->getPos().y)
		{
			knifes[i]->setVisible(false);
		}
	}
}

void Archer_knife::setListMonster(std::vector<Character*> listMonsters)
{
	for (int i = 0; i < listMonsters.size(); i++)
	{
		mListMonsters.push_back(listMonsters[i]);
	}
}

void Archer_knife::update()
{
	for (int j = 0; j < mListMonsters.size(); j++)
	{
		if (mListMonsters[j]->getPos().x >= getPos().x - mRange && mListMonsters[j]->getPos().x <= getPos().x)
		{
			mSprite->setFlipX(true);
			turnOnKnife(mListMonsters[j]->getPos());
		}
		if (mListMonsters[j]->getPos().x >= getPos().x  && mListMonsters[j]->getPos().x <= getPos().x + mRange)
		{
			mSprite->setFlipX(false);
			turnOnKnife(mListMonsters[j]->getPos());
		}
	}
	reuseKnife();
	shootKnife();
	collision();
}

void Archer_knife::init()
{
	mFrameCount = 0;
	mSpeed = 10;
	mRange = 200;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_ARCHER_ATTACK_KNIFE, NAME_PNG_ARCHER_ATTACK_KNIFE, COUNT_IMG_ARCHER_ATTACK_KNIFE, mSpeed, 0);
}
