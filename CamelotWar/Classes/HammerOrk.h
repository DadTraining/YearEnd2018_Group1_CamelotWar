#pragma once
#include <string>
#include <vector>

#include "cocos2d.h"
#include "Character.h"
#include "Model.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"


class HammerOrk :public Character
{

private:
	int mCount;

public:
	HammerOrk();
	~HammerOrk();
	HammerOrk(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();
private:
	int changeStatus;
	int countFrame = 0;
};