#pragma once
#include "Character.h"
#include "cocos2d.h"
#include <vector>

using namespace std;


class SpearKnight :
	public Character
{
public:
	SpearKnight();
	~SpearKnight();
	SpearKnight(cocos2d::Scene *scene);

	void walk() override;
	void attack() override;
	void die() override;

	void setListMonster(std::vector<Character*> listMonsters);
	void collision();


	void update() override;
	void init() override;
private:
	std::vector< Character*> mListMonsters;
	int mFrameCount;
	bool hasAnimated;
	int countFrame = 0;
};

