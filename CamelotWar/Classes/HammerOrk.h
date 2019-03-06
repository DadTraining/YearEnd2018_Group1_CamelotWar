#pragma once
#include "Character.h"

class HammerOrk :public Character
{
public:
	HammerOrk();
	~HammerOrk();
	HammerOrk(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void collision();
	void setListMonster(std::vector<Character*> listMonsters) override;
	void update() override;
	void init() override;
private:
	int countFrame = 0;
};