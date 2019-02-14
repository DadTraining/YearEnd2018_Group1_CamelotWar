#include "Troll.h"
#include "Defines.h"

Troll::Troll()
{
}

Troll::~Troll()
{
}

Troll::Troll(cocos2d::Scene * scene)
{
	setAnimation(NAME_PLIST_TROLL, NAME_PNG_TROLL,COUNT_IMG_TROLL,cocos2d::Vec2(250,200), scene);
	setStep(1);
}

void Troll::update()
{
	setPos(getPos() + cocos2d::Vec2(getStep(), 0));
}

void Troll::init()
{
}

void Troll::setStep(int step)
{
	mStep = step;
}

int Troll::getStep()
{
	return mStep;
}
