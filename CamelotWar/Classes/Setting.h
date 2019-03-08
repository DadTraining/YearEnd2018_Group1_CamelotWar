#pragma once
#include "PopUp.h"
#include "ui/CocosGUI.h"
class Setting :
	public PopUp
{
public:
	virtual bool init() override;
	void sliderBGM();
	void sliderSFX();
	void setVisible(bool);
	bool isVisible();

	CREATE_FUNC(Setting);
private:
	cocos2d::Sprite *mSfx, *mBgm;
	int mPercentSFX, mPercentBGM;
	bool mVisible;
};

