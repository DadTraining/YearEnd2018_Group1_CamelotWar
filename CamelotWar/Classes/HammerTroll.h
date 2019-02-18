#pragma once
#include "Character.h"
class HammerTroll :	public Character
{
public:
	HammerTroll();
	~HammerTroll();
	HammerTroll(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();
private:
	int changeStatus;
	int countFrame=0;
};