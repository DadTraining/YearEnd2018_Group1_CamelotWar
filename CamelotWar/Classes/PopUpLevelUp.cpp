#include "PopUpLevelUp.h"
#include "Defines.h"
USING_NS_CC;

bool PopUpLevelUp::init()
{
	PopUp::init();
	/*PopUp::setBackground();*/
	mLevelUp = cocos2d::Sprite::create(LEVEL_UP);
	mLevelUp->setPosition(0, 0);


	mLayer->addChild(mLevelUp);
	////////////////
	//Add button accept
	auto btnAccept = cocos2d::ui::Button::create(BUTTON_ACCEPT);
	btnAccept->setPosition(cocos2d::Vec2(0, -mLevelUp->getContentSize().height/1.5));


	mLayer->addChild(btnAccept);
	btnAccept->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType t) {
		switch (t)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:

			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			disappear();
			mLayer->setVisible(false);
			//mLayer->removeFromParentAndCleanup(true);
			break;
		}
	});
	return true;
}

void PopUpLevelUp::setVisible(bool visible)
{
	mLayer->setVisible(visible);
}
