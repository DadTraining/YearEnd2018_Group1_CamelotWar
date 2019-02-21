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

	void turnOnArrow(cocos2d::Vec2 pos);

	void setPosAll(cocos2d::Vec2 pos);

	void shootArrow();

	void collision();

	void reuseArrow();

	void setListMonster(std::vector<Character*> listMonsters);

	void update();
	void init();
private: 

	vector<Arrow*> arrows;
	std::vector< Character*> mListMonsters;
	int mFrameCount;
};

