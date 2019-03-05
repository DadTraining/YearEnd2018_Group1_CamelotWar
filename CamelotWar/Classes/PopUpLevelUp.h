#pragma once
#include "PopUp.h"
#include "ui\CocosGUI.h"
class PopUpLevelUp :
	public PopUp
{
public:
	virtual bool init() override;
	void setVisible(bool);

	CREATE_FUNC(PopUpLevelUp);
private:
	cocos2d::Sprite *mLevelUp;
};

