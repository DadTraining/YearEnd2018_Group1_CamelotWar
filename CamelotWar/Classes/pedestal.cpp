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
}

Pedestal::~Pedestal()
{
}


void Pedestal::update()
{
	
}

void Pedestal::init()
{
}
