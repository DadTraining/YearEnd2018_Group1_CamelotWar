#pragma once
#include "cocos2d.h"
#include "Model.h"
class Character : Model
{
public:
	Character(); 
	~Character();
	Character(cocos2d::Scene* scene);

	void update();
	void init();
	
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


private:
	int mHP;
	int mPrice;
	int mDamage;
	int mSpeed;
};


