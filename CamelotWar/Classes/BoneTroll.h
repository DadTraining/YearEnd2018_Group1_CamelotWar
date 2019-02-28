#pragma once
#include "Character.h"

class BoneTroll :public Character
{
public:
	BoneTroll();
	~BoneTroll();
	BoneTroll(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void collision();
	void update();
	void init();
private:
	int countFrame = 0;
};

