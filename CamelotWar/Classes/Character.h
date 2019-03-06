#pragma once

#include "cocos2d.h"
#include "Model.h"
#include "ui/CocosGUI.h"
#include "Castle.h"
#include "coin/CoinModel.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


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
	bool getCheckFallDone();
	void setCheckFallDone(bool check);
	void setPosHp(cocos2d::Vec2 pos);
	void setPosAll(cocos2d::Vec2 pos);
	void setPosRange();
	void levleUp();
	void setLevle(int lv);
	int getpriceToUpLv();

	void setStarOfHero();

	virtual void setListMonster(std::vector<Character*> listMonsters) = 0;
	
	int getAlive();
	int getPrice();
	int getLvOfHero();
	
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
	int lvOfHero;
	int priceToUpLv;

	bool mAppear;
	bool mCheckAtk;
	bool checkAppear;
	bool checkBuff;
	bool checkFallDone;
	Castle * mCastle;
	std::vector<CoinModel *> coins;
	cocos2d::Sprite* mHpBar;
	cocos2d::PhysicsBody* mPhysicsBody;
	cocos2d::ui::LoadingBar * mloadingHpBar;
	cocos2d::Sprite * mRangeLeft;
	cocos2d::Sprite * mRangeRight;
	cocos2d::Sprite * mStarOfHero;
};