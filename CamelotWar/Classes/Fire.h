#pragma once
#include "Model.h"
class Fire : public Model
{
public:
	Fire(cocos2d::Scene*scene);
	~Fire();

	void init() override;
	void fly(cocos2d::Vec2 pos);
	void update() override;

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

