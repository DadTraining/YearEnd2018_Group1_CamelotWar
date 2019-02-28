#include "PopUp.h"
#include "Defines.h"
#include "ui/CocosGUI.h"

bool PopUp::init()
{
	if (!Node::init()) return false;

	mLayer = cocos2d::Layer::create();
	mLayer->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	mLayer->setPosition(SCREEN_W / 2, SCREEN_H / 2);
	addChild(mLayer);
	return true;
}

void PopUp::setBackground()
{
	mBackground = cocos2d::Sprite::create(DIALOG_MAP);
	mBackground->setPosition(0, 0);

	mLayer->addChild(mBackground);
}

void PopUp::disappear()
{
	auto dis = cocos2d::TargetedAction::create(mLayer, cocos2d::FadeOut::create(3));
	this->runAction(dis);
}

cocos2d::Layer* PopUp::getLayer()
{
	return mLayer;
}