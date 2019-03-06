#include "pedestal.h"
#include "Defines.h"

Pedestal::Pedestal()
{
}

Pedestal::Pedestal(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_PEDESTAL);
	setPos(cocos2d::Vec2(250,250));
	scene->addChild(mSprite);
	init();
}

Pedestal::~Pedestal()
{
}


void Pedestal::update()
{
	
}

int Pedestal::getBuffATK()
{
	return buffATK;
}

void Pedestal::setBuffATK(int buff)
{
	buffATK = buff;
}

int Pedestal::getBuffSpeed()
{
	return buffSpeed;
}

void Pedestal::setBuffSpeed(int buff)
{
	buffSpeed = buff;
}

int Pedestal::getBuffRange()
{
	return buffRange;
}

void Pedestal::setBuffRange(int buff)
{
	buffRange = buff;
}

void Pedestal::init()
{
	buffATK = 1;
	buffSpeed = 1;
	buffRange = 1;

}

cocos2d::Rect Pedestal::getBoudingBox()
{
	cocos2d::Rect boudingbox = mSprite->getBoundingBox();
	boudingbox.size.width -= 40;
	boudingbox.size.height -= 40;

	boudingbox.setRect(getPos().x - 60, getPos().y, boudingbox.size.width-20, boudingbox.size.height - 40);
	return boudingbox;
}
