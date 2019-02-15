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

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

	void update();
	void init();
private: 

	vector<Arrow*> arrows;
	int mFrameCount;
};

