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

	init();
}


bool Archer::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (mloadingHpBar->getPercent() > 0)
	{
		mloadingHpBar->setPercent(mloadingHpBar->getPercent() - 20);
	}
	else
	{
		setAnimation(NAME_PLIST_ARCHER_DIE, NAME_PNG_ARCHER_DIE, COUNT_IMG_ARCHER_DIE);
	}
	return false;
}

void Archer::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void Archer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void Archer::update()
{
	if (mloadingHpBar->getPercent() > 0)
	{
		//setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK,COUNT_IMG_ARCHER_ATTACK);
	}
}

void Archer::init()
{
	getHpBar()->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK, COUNT_IMG_ARCHER_ATTACK);

}