#include "Archer.h"
#include "Defines.h"



Archer::Archer()
{
}


Archer::~Archer()
{
}

Archer::Archer(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER);
	setPos(cocos2d::Vec2(SCREEN_W / 3, SCREEN_H / 3));
	scene->addChild(mSprite);

	for (int i = 0; i < 10; i++) {
		auto arrow = new Arrow(scene);
		arrow->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
		arrows.push_back(arrow);
		arrow->setVisible(false);
	}

	init();
}

void Archer::walk()
{
}

void Archer::attack()
{
}

void Archer::die()
{
}


void Archer::update()
{
	mFrameCount++;
	if (mFrameCount % 30 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (arrows[i]->isVisible() == false)
			{
				arrows[i]->setVisible(true);
				break;
			}
		}
	}

		for (int i = 0; i < 10; i++)
		{
			if (arrows[i]->isVisible() == true)
			{
				arrows[i]->setPos(arrows[i]->getPos() + cocos2d::Vec2(10, 0));
				if (arrows[i]->getPos().x >= SCREEN_W + 20) {
					arrows[i]->setVisible(false);
					arrows[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
				}
			}
		}
}

void Archer::init()
{
	mFrameCount = 0;
	mSpeed = 20;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK, COUNT_IMG_ARCHER_ATTACK,mSpeed,0);

}