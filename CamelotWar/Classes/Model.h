#pragma once
#include "cocos2d.h"
class Model
{
public:
	Model();
	Model(cocos2d::Scene *scene);
	
	cocos2d::Sprite* getSprite();
	void setSprite(cocos2d::Sprite* sprite);

	cocos2d::Vec2 getPos();
	void setPos(cocos2d::Vec2 pos);

	virtual void update() = 0;
	virtual void init() = 0;
	~Model();

private:
	cocos2d::Sprite* mSprite;
};

