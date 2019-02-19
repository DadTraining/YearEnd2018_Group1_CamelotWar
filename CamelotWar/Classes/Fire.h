#pragma once
#include "Model.h"
class Fire : public Model
{
public:
	Fire(cocos2d::Scene*scene);
	~Fire();

	void init();
	void update();

	void setVisible(boolean visible);
	boolean isVisible();
	void setSpeed(int);
	int getSpeed();

private:
	int mSpeed;
};

