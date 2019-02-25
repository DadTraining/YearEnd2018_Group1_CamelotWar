#pragma once
#include "Model.h"
class Fire : public Model
{
public:
	Fire(cocos2d::Scene*scene);
	~Fire();

	void init();
	void fly(cocos2d::Vec2 pos);
	void update();

	void setVisible(boolean visible);
	boolean isVisible();

	void setMFire(boolean fire);
	void setSpeed(int);
	int getSpeed();

private:
	int mSpeed;
	boolean mFire;
	float a;
	float b;
};

