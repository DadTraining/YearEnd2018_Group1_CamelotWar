#pragma once
#include "cocos2d.h"
#include "Model.h"
class Character : Model
{
public:
	Character(); 
	~Character();
	Character(cocos2d::Scene* scene);

	virtual void update();
	virtual void init();
	
	void deCreaseHP();
	void reBorn();

	int getHP();
	void setHP(int hp);
	int getPrice();
	void setPrice(int price);
	int getDamage();
	void setDamage(int damage);
	int getSpeed();
	void setSpeed(int speed);
	int getRange();
	void setRange(int range);

	cocos2d::Sprite* getHpBar();
	void setHpBar(cocos2d::Sprite* hpBar);

	void deCreaseHpBar();

private:
	int mHP;
	int mPrice;
	int mDamage;
	int mSpeed;
	int mRange;
	cocos2d::Sprite* mHpBar;
};


