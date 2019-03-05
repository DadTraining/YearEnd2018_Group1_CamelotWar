#pragma once

#include "cocos2d.h"
#include "Model.h"
#include "ui/CocosGUI.h"
#include "Castle.h"
#include "coin/CoinModel.h"

class Character : public Model
{
public:
	Character(); 
	~Character();
	Character(cocos2d::Scene* scene);
	
	void setcheckAppear(bool appear);
	void setCheckATK(bool checkATK);
	void setVisibleHP(bool visible);
	void setAlive(int alive);
	void setVisibleCoin(bool visible, int i);
	void setCastle(Castle *castle);
	void setAppear(bool appear);
	void setPosHp(cocos2d::Vec2 pos);
	void setPosAll(cocos2d::Vec2 pos);
	void setPosRange();
	
	int getAlive();
	int getPrice();
	
	bool getAppear();
	bool getcheckAppear();
	bool getCheckATK();
	
	std::vector<CoinModel*> getCoin();
	cocos2d::Rect getBoudingBoxCoin(int i);
	
	void deCreaseHP(int hp);
	void reBorn();
	void addPhysicsBody();
	void setvisibleRange(bool visible);
	void init() override;
	
	virtual void walk()=0;
	virtual	void attack()=0;
	virtual void die() = 0;;
	
protected:

	int mHP;
	int mPrice;
	int mDamage;
	int mSpeed;
	int mRange;
	int mAlive;
	int countFrame;
	int changeStatus;
	bool mAppear;
	bool mCheckAtk;
	bool checkAppear;
	bool checkBuff;
	Castle * mCastle;
	std::vector<CoinModel *> coins;
	cocos2d::Sprite* mHpBar;
	cocos2d::PhysicsBody* mPhysicsBody;
	cocos2d::ui::LoadingBar * mloadingHpBar;
	cocos2d::Sprite * mRangeLeft;
	cocos2d::Sprite * mRangeRight;
};