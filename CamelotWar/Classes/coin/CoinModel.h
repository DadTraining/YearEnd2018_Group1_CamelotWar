#pragma once

#include "Model.h"

#include "cocos2d.h"

class CoinModel : public Model
{
private:
	cocos2d::PhysicsBody* mPhysicsBody;
    cocos2d::Vector<cocos2d::SpriteFrame*> mSpriteFrames;
	cocos2d::Label* lable;
	bool mCheckFall;

public:
    CoinModel(cocos2d::Scene* scene);
    CoinModel(cocos2d::Node* node);
    ~CoinModel();

	void removeCoin();

	void PushCoin(cocos2d::Vec2 velocity);

	void setDynamic(bool dynamic);

	void setCheckFall(bool checkfall);
	bool getCheckFall();
		
    void init() override;
	void CoinPriceFly(int price, cocos2d::Vec2 pos);
	void update() override;
};
