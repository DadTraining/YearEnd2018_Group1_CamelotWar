#pragma once

#include "cocos2d.h"
#include <string>

class Model
{
public:
	Model();
	Model(cocos2d::Scene *scene);
	~Model();
	
	cocos2d::Vec2 getPos();
	void setPos(cocos2d::Vec2 pos);

	void setAnimation(std::string namePlist, char * namePng, int CountImage,int speed,int repeat);

	virtual void update() = 0;
	virtual void init() = 0;

protected:
	cocos2d::Sprite* mSprite;
};