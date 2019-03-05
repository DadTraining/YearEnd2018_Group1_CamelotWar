#include "Coin.h"
#include "cocos2d.h"
#include "Defines.h"



Coin::Coin(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create(IMG_COIN);
	scene->addChild(mSprite);

	init();
}

Coin::~Coin()
{
}

void Coin::update()
{
}

void Coin::init()
{
}
