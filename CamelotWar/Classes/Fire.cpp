#include "Fire.h"
#include "cocos2d.h"
#include "Defines.h"


Fire::Fire(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create(IMG_Fire);

	scene->addChild(mSprite);
	setSpeed(10);
	init();
}


Fire::~Fire()
{
}

void Fire::init()
{
}

void Fire::update()
{
}

void Fire::setVisible(boolean visible)
{
	mSprite->setVisible(visible);
}

boolean Fire::isVisible()
{
	return mSprite->isVisible();
}

void Fire::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Fire::getSpeed()
{
	return mSpeed;
}
