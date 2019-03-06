#pragma once
#include <string>
#include <vector>

#include "cocos2d.h"
#include "Character.h"
#include "Model.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Troll : public Character
{
public:
	Troll();
	~Troll();
	Troll(cocos2d::Scene * scene);

	void walk() override;
	void attack() override;
	void die() override;

	void collision();

	void setListMonster(std::vector<Character*> listMonsters) override;
	void update() override;
	void init() override;
  
private:
	int changeStatus;

};
