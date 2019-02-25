#pragma once
#include "Model.h"
class Arrow :public Model
{
public:
	Arrow(cocos2d::Scene*scene);
	~Arrow();

	void init();
	void fly(cocos2d::Vec2 pos);
	void update();
	
	void setVisible(boolean visible);
	boolean isVisible();

	void setMShoot(boolean shoot);

	void setSpeed(int);
	int getSpeed();
private:
	int mSpeed;
	boolean mShoot;
	float a;
	float b;
};

