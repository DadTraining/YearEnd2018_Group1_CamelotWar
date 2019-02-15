#include "Troll.h"
#include "Defines.h"


Troll::Troll()
{
	
}

Troll::~Troll()
{

}

Troll::Troll(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_TROLL);
	scene->addChild(mSprite);

	init();
}

void Troll::trollWalk()
{
	setPos(mSprite->getPosition() + cocos2d::Vec2(1, 0));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
}

void Troll::trollATK()
{
	
}

void Troll::update()
{
	if (getPos().x == SCREEN_W/2)
	{
		trollATK();
	}
	else
	{
		trollWalk();
	
	}
}

void Troll::init()
{
	setPos(cocos2d::Vec2(MONSTER_APPEAR, SCREEN_H / 3));
	setPosHp(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	setAnimation(NAME_PLIST_TROLL_WALK, NAME_PNG_TROLL_WALK, COUNT_IMG_TROLL_WALK,0);
}
  
int Troll::getStep()
{
	return mStep;
}
