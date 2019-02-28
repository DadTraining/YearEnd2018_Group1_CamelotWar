#pragma once
#include "Model.h"
class Coin : public Model
{
public:
	Coin(cocos2d::Scene *scene);
	~Coin();

	void update();
	void init();
};

