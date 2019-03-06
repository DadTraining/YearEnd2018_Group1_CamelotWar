#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "Knife.h"
#include <vector>
#include "pedestal.h"

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
	void flip(bool flip);

	void turnOnKnife(cocos2d::Vec2 pos);
	void shootKnife();
	void collision();
	void reuseKnife();
	void setListPedestal(std::vector<Pedestal*> listPedestals);
	void setListMonster(std::vector<Character*> listMonsters) override;

	void update() override;
	void init() override;

	void collisionWithPedestal();

private :
	vector<Knife*> knifes;
	std::vector< Character*> mListMonsters;
	std::vector<Pedestal *> mListPedestals;
	int mFrameCount;
	bool hasAnimated;
};

