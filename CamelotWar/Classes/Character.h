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
	
	void deCreaseHP(int hp);

	void reBorn();

	void setPosAll(cocos2d::Vec2 pos);
	
	virtual void walk()=0;
	virtual	void attack()=0;
	virtual void die() = 0;;


	void init() override;

	std::vector<CoinModel*> getCoin();

	int getPrice();
	void setVisibleCoin(bool visible, int i);


	void setVisibleHP(bool visible);

	void setAlive(int alive);
	int getAlive();

	void setCastle(Castle *castle);
	void setAppear(bool appear);
	bool getAppear();

	cocos2d::Rect getBoudingBoxCoin(int i);

	void setcheckAppear(bool appear);
	bool getcheckAppear();

	void setCheckATK(bool checkATK);
	bool getCheckATK();

	void setPosHp(cocos2d::Vec2 pos);

	void addPhysicsBody();
	
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
	Castle * mCastle;
	std::vector<CoinModel *> coins;
	cocos2d::Sprite* mHpBar;
	cocos2d::PhysicsBody* mPhysicsBody;
	cocos2d::ui::LoadingBar * mloadingHpBar;
};