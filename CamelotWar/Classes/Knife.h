#pragma once
#include "Model.h"
class Knife :public Model 
{
public:
	Knife(cocos2d::Scene *scene);
	~Knife();

	void init();
	void fly(cocos2d::Vec2 pos);
	void update();

	void setVisible(bool visible);
	bool isVisible();

	void setMShoot(bool shoot);
	void setSpeed(int);
	int getSpeed();

private:
	int mSpeed;
	bool mShoot;
	float a;
	float b;
};

