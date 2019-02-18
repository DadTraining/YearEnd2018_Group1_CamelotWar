#pragma once
#include "Model.h"
class Knife :public Model 
{
public:
	Knife(cocos2d::Scene *scene);
	~Knife();

	void init();
	void update();

	void setVisible(boolean visible);
	boolean isVisible();
	void setSpeed(int);
	int getSpeed();

private:
	int mSpeed;
};

