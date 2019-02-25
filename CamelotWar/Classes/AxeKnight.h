#pragma once
#include "Character.h"
class AxeKnight :
	public Character
{
public:
	AxeKnight();
	~AxeKnight();
	AxeKnight(cocos2d::Scene *scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();
};

