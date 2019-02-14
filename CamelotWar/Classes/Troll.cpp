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
	
}

void Troll::update()
{
}

void Troll::init()
{
}
