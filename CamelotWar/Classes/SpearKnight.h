#pragma once
#include "Character.h"
class SpearKnight :
	public Character
{
public:
	SpearKnight();
	~SpearKnight();
	SpearKnight(cocos2d::Scene *scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();
};

