#pragma once
#include "Character.h"
class SwordKnight :
	public Character
{
public:
	SwordKnight();
	~SwordKnight();
	SwordKnight(cocos2d::Scene *scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();
};

