#pragma once

#include "cocos2d.h"
#include "Character.h"

class Troll : public Character
{
public:
	Troll();
	~Troll();
	Troll(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;
	void update();
	void init();
private:
	int changeStatus;
};

