#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "Fire.h"
#include <vector>
#include "pedestal.h"

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
	void setListPedestal(std::vector<Pedestal*> listPedestals);
	void flip(bool flip);

	void turnOnFire(cocos2d::Vec2 pos);
	void shootFire();
	void collision();
	void reuseFire();
	void setListMonster(std::vector<Character*> listMonsters) override;

	void update() override;
	void init() override;

	void collisionWithPedestal();

private:
	vector<Fire*> fires;
	std::vector< Character*> mListMonsters;
	std::vector<Pedestal *> mListPedestals;
	int mFrameCount;
	bool hasAnimated;
};

