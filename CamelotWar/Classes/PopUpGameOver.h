#pragma once
#include "PopUp.h"
#include "ui\CocosGUI.h"
class PopUpGameOver :
	public PopUp
{
public:
	virtual bool init() override;
	void setVisible(bool);

	void setNewvalue(std::string string);

	CREATE_FUNC(PopUpGameOver);
private:
	cocos2d::Sprite *mGameOver;
};

