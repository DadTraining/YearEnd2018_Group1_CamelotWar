#pragma once
#include "cocos2d.h"
#include "Troll.h"
#include "PopUpSetting.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
class TitleScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void loadMusic();
	void update(float delta);

	// a selector callback
	void menuPlayCallback(cocos2d::Ref* pSender);
	void menuSettingCallback(cocos2d::Ref* pSender);
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(TitleScene);
private:
	PopUpSetting *setting;
	CocosDenshion::SimpleAudioEngine *mBGM;
	CocosDenshion::SimpleAudioEngine *mSFX;
};
