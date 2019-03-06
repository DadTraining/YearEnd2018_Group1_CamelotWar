#pragma once
#include "Character.h"

class SwordOrk :public Character
{
public:
	SwordOrk();
	~SwordOrk();
	SwordOrk(cocos2d::Scene * scene);

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

