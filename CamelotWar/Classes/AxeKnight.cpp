#include "AxeKnight.h"
#include "Defines.h"


AxeKnight::AxeKnight()
{
}


AxeKnight::~AxeKnight()
{
}

AxeKnight::AxeKnight(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_AXEKNIGHT);
	setPos(cocos2d::Vec2(SCREEN_W / 4 * 3, SCREEN_H / 4 + 75));
	scene->addChild(mSprite);
	init();
}

void AxeKnight::walk()
{
}

void AxeKnight::attack()
{
}

void AxeKnight::die()
{
}

void AxeKnight::update()
{
}

void AxeKnight::init()
{
	mSpeed = 20;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_AXEKNIGHT_ATK, NAME_PNG_AXEKNIGHT_ATK, COUNT_IMG_AXEKNIGHT_ATK, mSpeed, 0);
}