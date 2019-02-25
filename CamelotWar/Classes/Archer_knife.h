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
	void flip(boolean flip);

	void turnOnKnife(cocos2d::Vec2 pos);
	void shootKnife();
	void collision();
	void reuseKnife();
	void setListMonster(std::vector<Character*> listMonsters);

	void update();
	void init();

private :
	vector<Knife*> knifes;
	std::vector< Character*> mListMonsters;
	int mFrameCount;
	bool hasAnimated;
};

