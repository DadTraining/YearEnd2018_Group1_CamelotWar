#pragma once

#include <string>
#include <vector>

#include "Character.h"
#include "Model.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Troll : public Character
{
private:
	int mCount;

public:
	Troll();
	~Troll();
	Troll(cocos2d::Scene * scene);

	void update();
	void init();
};