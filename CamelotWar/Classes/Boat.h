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
	virtual void update();
	virtual void init();
	void collision();
	void setListMonster(std::vector<Character*> listMonsters);
	bool BoatTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	void BoatTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	void BoatTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);
protected:
	std::vector< Character*> mListMonsters;
};
