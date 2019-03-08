#include "PopUpGameOver.h"
#include "Defines.h"
#include "TitleScene.h"
#include "HelloWorldScene.h"

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
			cocos2d::Director::getInstance()->replaceScene(HelloWorld::createScene());
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
			cocos2d::Director::getInstance()->replaceScene(TitleScene::createScene());
			break;
		}
	});
	return true;
}

void PopUpGameOver::setVisible(bool visible)
{
	mLayer->setVisible(visible);
}

void PopUpGameOver::setNewvalue(std::string string)
{
	mGameOver->setTexture(string);
}