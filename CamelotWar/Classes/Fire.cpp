#include "Fire.h"
#include "cocos2d.h"
#include "Defines.h"


Fire::Fire(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create(IMG_FIRE);

	scene->addChild(mSprite);
	mSpeed = 20;
	init();
}


Fire::~Fire()
{
}

void Fire::init()
{
}

void Fire::fly(cocos2d::Vec2 pos)
{
	a = (pos.y - getPos().y) / (pos.x - getPos().x);
	b = pos.y - (a*pos.x);
}

void Fire::update()
{
	float y = getPos().y - mSpeed;
	float x = (y - b) / a;
	setPos(cocos2d::Vec2(x, y));
}

void Fire::setVisible(boolean visible)
{
	mSprite->setVisible(visible);
}

boolean Fire::isVisible()
{
	return mSprite->isVisible();
}

void Fire::setMFire(boolean fire)
{
	mFire = fire;
}

void Fire::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Fire::getSpeed()
{
	return mSpeed;
}
