#pragma once
#include "Character.h"

class AxeOrk :public Character
{
public:
	AxeOrk();
	~AxeOrk();
	AxeOrk(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void collision();
	void update() override;
	void init() override;
private:
	int countFrame = 0;
};