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
	setPos(cocos2d::Vec2(SCREEN_W / 3, SCREEN_H / 3));
	scene->addChild(mSprite);

	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Troll::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Troll::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Troll::onTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);

	init();
}


bool Troll::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (mloadingHpBar->getPercent() > 0)
	{
		mloadingHpBar->setPercent(mloadingHpBar->getPercent() - 20);
	}
	else
	{
		setAnimation(NAME_PLIST_TROLL_DIE,NAME_PNG_TROLL_DIE,COUNT_IMG_TROLL_DIE);
	}
	return false;
}

void Troll::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void Troll::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

void Troll::update()
{
	setPos(getPos() + cocos2d::Vec2(getStep(), 0));
	if (mloadingHpBar->getPercent() > 0)
	{
		//setAnimation(NAME_PLIST_TROLL_ATK, NAME_PNG_TROLL_ATK, COUNT_IMG_TROLL_ATK);
	}
}

void Troll::init()
{
	getHpBar()->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_TROLL_ATK, NAME_PNG_TROLL_ATK, COUNT_IMG_TROLL_ATK);
  setStep(1);
}

void Troll::setStep(int step)
{
	mStep = step;
}

int Troll::getStep()
{
	return mStep;
}
