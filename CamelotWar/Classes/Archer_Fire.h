#pragma once
#include "cocos2d.h"
#include "Character.h"
#include <vector>
#include "Fire.h"

using	namespace std;

class Archer_Fire : public Character
{
public:
	Archer_Fire();
	~Archer_Fire();

	Archer_Fire(cocos2d::Scene * scene);

	void setPosAll(cocos2d::Vec2 pos);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();

private:

	vector<Fire*> fires;
	int mFrameCount;
};

