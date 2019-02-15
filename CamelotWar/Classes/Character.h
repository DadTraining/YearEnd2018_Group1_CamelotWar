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
	void deCreaseHpBar();

	virtual void update();
	virtual void init();

	void setPosHp(cocos2d::Vec2 pos);
protected:
	int mHP;
	int mPrice;
	int mDamage;
	int mSpeed;
	int mRange;
	int mAlive;
	cocos2d::Sprite* mHpBar;
	cocos2d::ui::LoadingBar * mloadingHpBar;
};