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
	/*if (isVisible()) {
		setPos(getPos() + cocos2d::Vec2(getSpeed(), 0));
		if (getPos().x >= SCREEN_W + mSprite->getContentSize().width / 2) {
			setVisible(false);
		}
	}*/
}

void Arrow::setVisible(boolean visible)
{
	mSprite->setVisible(visible);
}

boolean Arrow::isVisible()
{
	return mSprite->isVisible();
}

void Arrow::setSpeed(int)
{
	mSpeed = mSpeed;
}

int Arrow::getSpeed()
{
	return mSpeed;
}
