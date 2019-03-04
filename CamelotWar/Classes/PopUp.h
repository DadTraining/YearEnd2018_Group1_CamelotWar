#pragma once
#include "cocos2d.h"
class PopUp :public cocos2d::Node
{
protected:
	cocos2d::Layer *mLayer;
	cocos2d::Sprite *mBackground;
public:
	virtual bool init();
	void setBackground();
	void disappear();

	cocos2d::Layer* getLayer();

	CREATE_FUNC(PopUp);
};