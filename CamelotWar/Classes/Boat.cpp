#include "Model.h"
#include "Boat.h"
#include "Defines.h"
#include "Character.h"

Boat::Boat(cocos2d::Scene *scene)
{
	init();
	scene->addChild(mSprite);
	
}

Boat::~Boat()
{
}

void Boat::update()
{
	collision();
}

void Boat::init()
{
	mSprite = cocos2d::Sprite::create(BOAT_NAME_SPRITE);
	setPos(cocos2d::Vec2(SCREEN_W / 2, BOAT_MIN_POSITION_Y));
}

void Boat::collision()
{
	for (int i = 0; i < mListMonsters.size(); i++)
	{
			if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()))
			{
				//mListMonsters[i]->setPos(cocos2d::Vec2(mListMonsters[i]->getPos().x, SCREEN_H/2));
				mListMonsters[i]->reBorn(mListMonsters[i]);
			}
	}
}


void Boat::setListMonster(std::vector<Character*> listMonsters)
{
	for (int i = 0; i < listMonsters.size(); i++)
	{
		mListMonsters.push_back(listMonsters[i]);
	}
}

bool Boat::BoatTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (mSprite->getBoundingBox().containsPoint(touch->getLocation()))
	{
		return true;
	}
	return false;
}

void Boat::BoatTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (touch->getLocation().x < getPos().x)
	{
		mSprite->setFlipX(false);
	}
	else {
		mSprite->setFlipX(true);
	}
    setPos(cocos2d::Vec2(touch->getLocation().x, BOAT_MIN_POSITION_Y));
	
}

void Boat::BoatTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

