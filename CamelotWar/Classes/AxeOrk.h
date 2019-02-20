#pragma once
#include "Character.h"
class AxeOrk :
	public Character
{
public:
	AxeOrk();
	~AxeOrk();
	AxeOrk(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();
private:
	int changeStatus;
	int countFrame = 0;
};