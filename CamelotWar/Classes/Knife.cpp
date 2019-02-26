#include "Knife.h"
#include "cocos2d.h"
#include "Defines.h"


Knife::Knife(cocos2d::Scene* scene)
{
	mSprite = cocos2d::Sprite::create(IMG_KNIFE);
	mSprite->setScale(1.5);
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

	//set the rotatuion for the arrow
	cocos2d::Vec2 delta = pos - getPos();
	mSprite->setRotation(atan2(delta.x, delta.y) * 180 / M_PI - 90);
}
void Knife::update()
{
	float y = getPos().y - mSpeed;
	float x = (y - b) / a;
	setPos(cocos2d::Vec2(x, y));
}



void Knife::setVisible(bool visible)
{
	mSprite->setVisible(visible);
}

bool Knife::isVisible()
{
	return mSprite->isVisible();
}

void Knife::setMShoot(bool shoot)
{
	mShoot = shoot;
}

void Knife::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Knife::getSpeed()
{
	return mSpeed;
}
