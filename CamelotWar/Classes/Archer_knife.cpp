#include "Archer_knife.h"
#include "Defines.h"



Archer_knife::Archer_knife()
{
}


Archer_knife::~Archer_knife()
{
}

Archer_knife::Archer_knife(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER_KNIFE);
	setPos(cocos2d::Vec2(SCREEN_W / 4, SCREEN_H / 4));
	scene->addChild(mSprite);

	for (int i = 0; i < 10; i++) {
		auto knife = new Knife(scene);
		knife->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width +20, getPos().y));
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

void Archer_knife::update()
{
	for (int i = 0; i < 10; i++)
	{
		knifes.at(i)->update();
	}

	mFrameCount++;
	if (mFrameCount % 30 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (knifes[i]->isVisible() == false)
			{
				knifes[i]->setVisible(true);
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (knifes[i]->isVisible() == true)
		{
			knifes[i]->setPos(knifes[i]->getPos() + cocos2d::Vec2(10, 0));
			if (knifes[i]->getPos().x >= SCREEN_W + 20) {
				knifes[i]->setVisible(false);
				knifes[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
			}
			if (knifes[i]->getPos().x == getPos().x + 50)
			{
				knifes[i]->update();
			}
		}
	}
}

void Archer_knife::init()
{
	mFrameCount = 0;
	mSpeed = 20;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_ARCHER_ATTACK_KNIFE, NAME_PNG_ARCHER_ATTACK_KNIFE, COUNT_IMG_ARCHER_ATTACK_KNIFE, mSpeed, 0);
}
