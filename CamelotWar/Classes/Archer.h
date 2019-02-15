#pragma once
#include "cocos2d.h"
#include "Character.h"
class Archer : public Character
{
public:
	Archer();
	~Archer();
	Archer(cocos2d::Scene * scene);

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

	void update();
	void init();
};

