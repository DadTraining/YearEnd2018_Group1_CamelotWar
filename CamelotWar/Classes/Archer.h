#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "Arrow.h"
#include <vector>
using namespace std;
class Archer : public Character
{
public:
	Archer();
	~Archer();
	Archer(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;
	void flip(boolean flip);

	void update();
	void init();
private: 

	vector<Arrow*> arrows;
	int mFrameCount;
};

