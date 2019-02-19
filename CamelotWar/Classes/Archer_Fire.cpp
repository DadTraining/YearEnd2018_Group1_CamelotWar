#include "Archer_Fire.h"
#include "Defines.h"



Archer_Fire::Archer_Fire()
{
}


Archer_Fire::~Archer_Fire()
{
}

Archer_Fire::Archer_Fire(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER);
	setPos(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	scene->addChild(mSprite);

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

void Archer_Fire::update()
{
	mFrameCount++;
	if (mFrameCount % 30 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (fires[i]->isVisible() == false)
			{
				fires[i]->setVisible(true);
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (fires[i]->isVisible() == true)
		{
			fires[i]->setPos(fires[i]->getPos() + cocos2d::Vec2(10, 0));
			if (fires[i]->getPos().x >= SCREEN_W + 20) {
				fires[i]->setVisible(false);
				fires[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
			}
		}
	}
}

void Archer_Fire::init()
{
	mFrameCount = 0;
	mSpeed = 20;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_ARCHER_ATTACK_Fire, NAME_PNG_ARCHER_ATTACK_Fire, COUNT_IMG_ARCHER_ATTACK_Fire, mSpeed, 0);

}
