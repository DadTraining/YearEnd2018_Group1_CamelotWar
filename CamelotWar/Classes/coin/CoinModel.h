#pragma once

#include "Model.h"

#include "cocos2d.h"

class CoinModel : public Model
{
private:
	cocos2d::PhysicsBody* mPhysicsBody;
    cocos2d::Vector<cocos2d::SpriteFrame*> mSpriteFrames;
	bool mCheckFall;

public:
    CoinModel(cocos2d::Scene* scene);
    CoinModel(cocos2d::Node* node);
    ~CoinModel();

	void PushCoin(cocos2d::Vec2 velocity);

	void setDynamic(bool dynamic);

	void setCheckFall(bool checkfall);
	bool getCheckFall();
		
    void init() override;
	void update() override;
};