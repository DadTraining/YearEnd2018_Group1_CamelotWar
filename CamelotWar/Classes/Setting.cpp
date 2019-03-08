#include "Setting.h"
#include "Defines.h"
#include "TitleScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;


bool Setting::init()
{
	PopUp::init();
	
	mBackground = cocos2d::Sprite::create(POPUP_SETTING);
	mBackground->setPosition(0, 0);

	mLayer->addChild(mBackground);

	/////////////////
	////Add label mBgm and mSfx
	mBgm = cocos2d::Sprite::create(LABEL_BGM);
	mBgm->setPosition(Vec2(-mBackground->getContentSize().width / 4, mBackground->getContentSize().height / 10));
	mLayer->addChild(mBgm);

	mSfx = cocos2d::Sprite::create(LABEL_SFX);
	mSfx->setPosition(Vec2(-mBackground->getContentSize().width / 4, -mBackground->getContentSize().height / 13));
	mLayer->addChild(mSfx);

	sliderBGM();
	sliderSFX();

	auto btnHome = cocos2d::ui::Button::create(BUTTON_HOME);
	btnHome->setPosition(cocos2d::Vec2(-mBackground->getContentSize().width / 4, -mBackground->getContentSize().height / 4));
	mLayer->addChild(btnHome);
	btnHome->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType t) {
		switch (t)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TitleScene::createScene());
			break;
		}
	});

	auto btnResume = cocos2d::ui::Button::create(BUTTON_RESUME);
	btnResume->setPosition(cocos2d::Vec2(0, -mBackground->getContentSize().height / 4));
	mLayer->addChild(btnResume);
	btnResume->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType t) {
		switch (t)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			disappear();
			mLayer->setVisible(false);
			mVisible = false;
			break;
		}
	});

	auto btnReset = cocos2d::ui::Button::create(BUTTON_RESET);
	btnReset->setPosition(cocos2d::Vec2(mBackground->getContentSize().width / 4, -mBackground->getContentSize().height / 4));
	mLayer->addChild(btnReset);
	btnReset->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType t) {
		switch (t)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(HelloWorld::createScene());
			break;
		}
	});

	return true;
}

void Setting::sliderBGM()
{

	auto sliderB = cocos2d::ui::Slider::create();
	sliderB->loadBarTexture(SLIDER_BAR_BROWN);
	sliderB->loadSlidBallTextureNormal(SLIDER_ROUND);
	sliderB->loadProgressBarTexture(SLIDER_BAR_BLUE);
	sliderB->setAnchorPoint(Vec2(0, 0.5));

	sliderB->setPosition(Vec2(-mBackground->getContentSize().width / 8, mBgm->getPosition().y));
	mLayer->addChild(sliderB);

	sliderB->addEventListener([&](Ref* sender, cocos2d::ui::Slider::EventType type) {
		switch (type)
		{
		case cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
		{
			cocos2d::ui::Slider *_slider = dynamic_cast<ui::Slider*>(sender);
			mPercentBGM = _slider->getPercent();
			break;
		}
		default:
			break;
		}
	});
}
void Setting::sliderSFX()
{
	auto sliderS = cocos2d::ui::Slider::create();
	sliderS->loadBarTexture(SLIDER_BAR_BROWN);
	sliderS->loadSlidBallTextureNormal(SLIDER_ROUND);
	sliderS->loadProgressBarTexture(SLIDER_BAR_ORANGE);
	sliderS->setAnchorPoint(Vec2(0, 0.5));
	sliderS->setPosition(Vec2(-mBackground->getContentSize().width / 8, mSfx->getPosition().y));
	mLayer->addChild(sliderS);

	sliderS->addEventListener([&](Ref* sender, cocos2d::ui::Slider::EventType type) {
		switch (type)
		{
		case cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
		{
			cocos2d::ui::Slider *_slider = dynamic_cast<ui::Slider*>(sender);
			mPercentSFX = _slider->getPercent();
			break;
		}
		default:
			break;
		}
	});
}

void Setting::setVisible(bool visible)
{
	mLayer->setVisible(visible);
	mVisible = visible;
}

bool Setting::isVisible()
{
	return mVisible;
}