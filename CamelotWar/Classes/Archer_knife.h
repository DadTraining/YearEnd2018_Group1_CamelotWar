#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "Knife.h"
#include <vector>

using namespace std;

class Archer_knife : public Character
{
public:
	Archer_knife();
	~Archer_knife();
	Archer_knife(cocos2d ::Scene *scene);

	void walk() override;
	void attack() override;
	void die() override;

	void update();
	void init();

private :
	vector<Knife*> knifes;
	int mFrameCount;
};

