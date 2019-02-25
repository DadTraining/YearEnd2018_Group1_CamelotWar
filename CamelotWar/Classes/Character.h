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
	
	void deCreaseHP(int hp);

	void reBorn(Character*);

	void setPosAll(cocos2d::Vec2 pos);
	
	virtual void walk()=0;
	virtual	void attack()=0;
	virtual void die() = 0;;


	virtual void init();

	void setAlive(int alive);
	int getAlive();

	void setAppear(bool appear);
	bool getAppear();


	void setPosHp(cocos2d::Vec2 pos);
protected:
	int mHP;
	int mPrice;
	int mDamage;
	int mSpeed;
	int mRange;
	int mAlive;
	bool mAppear;
	cocos2d::Sprite* mHpBar;
	cocos2d::ui::LoadingBar * mloadingHpBar;
	int changeStatus;

};