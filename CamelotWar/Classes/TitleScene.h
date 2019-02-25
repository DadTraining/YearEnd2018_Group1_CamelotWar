#pragma once
#include "cocos2d.h"
#include "Troll.h"

class TitleScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void update(float delta);

	// a selector callback
	void menuPlayCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(TitleScene);


};
