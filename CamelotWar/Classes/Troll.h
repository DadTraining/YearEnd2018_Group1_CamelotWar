#pragma once
#include "Character.h"
#include "AxeKnight.h"
class Troll : public Character
{
public:
	Troll();
	~Troll();
	Troll(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void collision();
	void update();
	void init();
  
private:
	int countFrame = 0;
};
