#include "SwordKnight.h"
#include "Defines.h"


SwordKnight::SwordKnight()
{
}


SwordKnight::~SwordKnight()
{
}

SwordKnight::SwordKnight(cocos2d::Scene * scene) :Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_SWORDKNIGHT);
	setPos(cocos2d::Vec2(SCREEN_W / 4 * 3, SCREEN_H / 4 + 140));
	scene->addChild(mSprite);
	init();
}

void SwordKnight::walk()
{
}

void SwordKnight::attack()
{
}

void SwordKnight::die()
{
}

void SwordKnight::update()
{
}

void SwordKnight::init()
{
	mSpeed = 20;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_SWORDKNIGHT_ATK, NAME_PNG_SWORDKNIGHT_ATK, COUNT_IMG_SWORDKNIGHT_ATK, mSpeed, 0);
}
