#pragma once

#include "cocos2d.h"
#include "Model.h"
#include "ui/CocosGUI.h"

class Character : public Model
{
public:
	Character(); 
	~Character();
	Character(cocos2d::Scene* scene);
	
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

	virtual void update();
	virtual void init();

protected:
	int mHP;
	int mPrice;
	int mDamage;
	int mSpeed;
	int mRange;
	cocos2d::Sprite* mHpBar;
	cocos2d::ui::LoadingBar * mloadingHpBar;
};