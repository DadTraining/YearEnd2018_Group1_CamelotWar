#include "Knife.h"
#include "cocos2d.h"
#include "Defines.h"



Knife::Knife(cocos2d::Scene* scene)
{
	mSprite = cocos2d::Sprite::create(IMG_Knife);

	scene->addChild(mSprite);
	setSpeed(10);
	init();
}


Knife::~Knife()
{
}

void Knife::init()
{
}

void Knife::update()
{
	mSprite->setRotation(mSprite->getRotation() + mSpeed);
}

void Knife::setVisible(boolean visible)
{
	mSprite->setVisible(visible);
}

boolean Knife::isVisible()
{
	return mSprite->isVisible();
}

void Knife::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Knife::getSpeed()
{
	return mSpeed;
}
