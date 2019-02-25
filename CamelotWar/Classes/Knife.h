#pragma once
#include "Model.h"
class Knife :public Model 
{
public:
	Knife(cocos2d::Scene *scene);
	~Knife();

	void init();
	void update();
	void fly(cocos2d::Vec2 pos);

	void setVisible(boolean visible);
	boolean isVisible();

	void setMKnife(boolean knife);
	void setSpeed(int);
	int getSpeed();

private:
	int mSpeed;
	boolean mKnife;
	float a;
	float b;
};

