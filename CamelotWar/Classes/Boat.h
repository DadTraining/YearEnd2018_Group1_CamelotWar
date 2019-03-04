#pragma once

#include "cocos2d.h"
#include "Model.h"
#include "ui/CocosGUI.h"
#include "Character.h"

class Boat : public Model
{
public:
	Boat(cocos2d::Scene*);
	~Boat();
	void update() override;
	void init() override;
	void collision();
	int getcoin();
	void setcoin(int acoin);

	void setListMonster(std::vector<Character*> listMonsters);

	void setListCharacter(std::vector<Character*> listCharacter);

	bool BoatTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	void BoatTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	void BoatTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);
protected:
	std::vector< Character*> mListMonsters;
	std::vector< Character*> mListCharacter;
	cocos2d::Label* lableCoin;
	int coin;
};
