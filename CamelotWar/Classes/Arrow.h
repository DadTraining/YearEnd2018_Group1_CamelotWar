#pragma once
#include "Model.h"
class Arrow :public Model
{
public:
	Arrow(cocos2d::Scene*scene);
	~Arrow();

	void init();
	void update();
	
	void setVisible(boolean visible);
	boolean isVisible();

	void setMShoot(boolean shoot);

	void setSpeed(int);
	int getSpeed();
private:
	int mSpeed;
	boolean mShoot;
};

