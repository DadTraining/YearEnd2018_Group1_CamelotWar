#pragma once
#include "PopUp.h"
#include "ui\CocosGUI.h"
class PopUpSetting :
	public PopUp
{
public:
	virtual bool init() override;
	virtual void onExit() override;
	void sliderBGM();
	void sliderSFX();

	CREATE_FUNC(PopUpSetting);
private:
	cocos2d::Sprite *mSfx, *mBgm;
	int mPercentSFX, mPercentBGM;
};