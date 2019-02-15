#pragma once

#include "cocos2d.h"
#include "Character.h"

class Troll : public Character
{
public:
	Troll();
	~Troll();
	Troll(cocos2d::Scene * scene);

	void trollWalk();
	void trollATK();
	void update();
	void init();
};

