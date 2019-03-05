#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "Arrow.h"
#include <vector>
#include "pedestal.h"

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
	void flip(bool flip);

	void turnOnArrow(cocos2d::Vec2 pos);

	void shootArrow();

	void collision();

	void reuseArrow();

	void setListMonster(std::vector<Character*> listMonsters);
	void setListPedestal(std::vector<Pedestal *> listPedestals);

	void update() override;
	void init() override;
	void collisionWithPedestal();
private: 

	vector<Arrow*> arrows;
	std::vector< Character*> mListMonsters;
	std::vector<Pedestal *> mListPedestals;
	int mFrameCount;
	bool hasAnimated;
};

