#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "Fire.h"
#include <vector>

using	namespace std;

class Archer_Fire : public Character
{
public:
	Archer_Fire();
	~Archer_Fire();
	Archer_Fire(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;
	void flip(boolean flip);

	void turnOnFire(cocos2d::Vec2 pos);
	void shootFire();
	void collision();
	void reuseFire();
	void setListMonster(std::vector<Character*> &listMonsters);

	void update();
	void init();

private:
	vector<Fire*> fires;
	std::vector< Character*> mListMonsters;
	int mFrameCount;
	bool hasAnimated;
};

