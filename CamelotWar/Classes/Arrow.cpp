#include "Arrow.h"
#include "cocos2d.h"
#include "Defines.h"

Arrow::Arrow(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create(IMG_Weapons);
	
	scene->addChild(mSprite);
	setSpeed(10);
	init();
}

Arrow::~Arrow()
{
}

void Arrow::init()
{

}

void Arrow::update()
{
	if (mShoot == true)
	{
		setPos(getPos() + cocos2d::Vec2(-10, 0));
	}
	else
	{
		setPos(getPos() + cocos2d::Vec2(10, 0));
	}
}

void Arrow::setVisible(boolean visible)
{
	mSprite->setVisible(visible);
}

boolean Arrow::isVisible()
{
	return mSprite->isVisible();
}

void Arrow::setMShoot(boolean shoot)
{
	mShoot = shoot;
}

void Arrow::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Arrow::getSpeed()
{
	return mSpeed;
}
