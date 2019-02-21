#include "Knife.h"
#include "cocos2d.h"
#include "Defines.h"



Knife::Knife(cocos2d::Scene* scene)
{
	mSprite = cocos2d::Sprite::create(IMG_KNIFE);

	scene->addChild(mSprite);
	mSpeed = 20;
	init();
}


Knife::~Knife()
{
}

void Knife::init()
{
}
void Knife::fly(cocos2d::Vec2 pos)
{
	a = (pos.y - getPos().y) / (pos.x - getPos().x);
	b = pos.y - (a * pos.x);
}
void Knife::update()
{
	mSprite->setRotation(mSprite->getRotation() + mSpeed);
	float y = getPos().y - mSpeed;
	float x = (y - b) / a;
	setPos(cocos2d::Vec2(x, y));
}



void Knife::setVisible(boolean visible)
{
	mSprite->setVisible(visible);
}

boolean Knife::isVisible()
{
	return mSprite->isVisible();
}

void Knife::setMKnife(boolean knife)
{
	mKnife = knife;
}

void Knife::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Knife::getSpeed()
{
	return mSpeed;
}
