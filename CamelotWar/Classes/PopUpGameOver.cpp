#include "PopUpGameOver.h"
#include "Defines.h"

bool PopUpGameOver::init()
{
	PopUp::init();
	mGameOver = cocos2d::Sprite::create(GAME_OVER);
	mGameOver->setPosition(0, 100);
	mLayer->addChild(mGameOver);

	auto btnYes = cocos2d::ui::Button::create(YES);
	btnYes->setPosition(cocos2d::Vec2(-125, -10));
	mLayer->addChild(btnYes);
	btnYes->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType t) {
		switch (t)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:

			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});

	auto btnNo = cocos2d::ui::Button::create(NO);
	btnNo->setPosition(cocos2d::Vec2(125, -10));
	mLayer->addChild(btnNo);
	btnNo->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType t) {
		switch (t)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:

			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	return true;
}

void PopUpGameOver::setVisible(bool visible)
{
	mLayer->setVisible(visible);
}
