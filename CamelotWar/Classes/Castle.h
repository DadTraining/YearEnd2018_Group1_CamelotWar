#pragma once
#include "cocos2d.h"
#include "Model.h"
#include "ui/CocosGUI.h"
using namespace std;

class Castle : public Model
{
public:
	Castle();
	Castle(cocos2d::Scene*scene);
	~Castle();

	void update();
	void init();
	void setPosHp(cocos2d::Vec2 pos);
	void deCreaseHP(int hp);
	cocos2d::ui::LoadingBar * Castle::getLoadingbar();

private:
	cocos2d::Sprite* mHpBar;
	cocos2d::ui::LoadingBar * mloadingHpBar;
	int mHP;
};

