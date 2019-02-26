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

