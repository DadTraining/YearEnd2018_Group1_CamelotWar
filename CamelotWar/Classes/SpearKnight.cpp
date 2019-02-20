#include "SpearKnight.h"
#include "Defines.h"


SpearKnight::SpearKnight()
{
}


SpearKnight::~SpearKnight()
{
}

SpearKnight::SpearKnight(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_SPEARKNIGHT);
	setPos(cocos2d::Vec2(SCREEN_W / 4 * 3, SCREEN_H / 4));
	scene->addChild(mSprite);
	init();
}

void SpearKnight::walk()
{
}

void SpearKnight::attack()
{
}

void SpearKnight::die()
{
}

void SpearKnight::update()
{
}

void SpearKnight::init()
{
	mSpeed = 20;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_SPEARKNIGHT_ATK, NAME_PNG_SPEARKNIGHT_ATK, COUNT_IMG_SPEARKNIGHT_ATK, mSpeed, 0);
}