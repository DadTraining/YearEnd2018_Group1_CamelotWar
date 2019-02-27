#include "SimpleAudioEngine.h"
#include "PopUpSetting.h"
#include "Defines.h"
USING_NS_CC;

bool PopUpSetting::init()
{
	PopUp::init();
	PopUp::setBackground();

	///////////////
	//Add label setting
	auto setting = cocos2d::Sprite::create(SETTING);
	setting->setPosition(Vec2(0, mBackground->getContentSize().height / 4));
	//setting->setPosition(Vec2::ZERO);
	mLayer->addChild(setting);

	///////////////
	//Add label mBgm and mSfx
	mSfx = cocos2d::Sprite::create(SFX);
	/*mSfx->setPosition(Vec2(-mBackground->getContentSize().width / 4,
		setting->getPosition().y - mBackground->getContentSize().height / 8));*/
	mSfx->setPosition(Vec2(-mBackground->getContentSize().width/4, mSfx->getContentSize().height * 0.75));
	mLayer->addChild(mSfx);

	mBgm = cocos2d::Sprite::create(BGM);
	/*mBgm->setPosition(Vec2(mSfx->getPosition().x,
		mSfx->getPosition().y - mBackground->getContentSize().height / 10));*/
	mBgm->setPosition(Vec2(-mBackground->getContentSize().width / 4, -mBgm->getContentSize().height * 0.75));
	mLayer->addChild(mBgm);

	////////////////
	//Add slider of mBgm and mSfx
	sliderBGM();
	sliderSFX();

	////////////////
	//Add button accept
	auto btnAccept = cocos2d::ui::Button::create(BUTTON_ACCEPT);
	/*btnAccept->setPosition(cocos2d::Vec2(0,
		-mBackground->getContentSize().height / 2
		+ mBackground->getContentSize().height / 10));*/
	btnAccept->setPosition(cocos2d::Vec2(0,-mBackground->getContentSize().height/4));
	

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

//void PopUpSetting::onExit()
//{
//	PopUp::onExit();
//}
void PopUpSetting::sliderBGM()
{

	auto sliderB = cocos2d::ui::Slider::create();
	sliderB->loadBarTexture(SLIDE_BAR_BG);
	sliderB->loadSlidBallTextureNormal(SLIDE_ROUND);
	sliderB->loadProgressBarTexture(SLIDE_BAR_PROGRESS);
	sliderB->setAnchorPoint(Vec2(0, 0.5));

	/*sliderB->setPosition(Vec2(mBgm->getPosition().x + mBackground->getContentSize().width / 12,
		mBgm->getPosition().y));*/
	sliderB->setPosition(Vec2(-mBgm->getContentSize().width/2, mBgm->getPosition().y));
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
void PopUpSetting::sliderSFX()
{

	auto sliderS = cocos2d::ui::Slider::create();
	sliderS->loadBarTexture(SLIDE_BAR_BG);
	sliderS->loadSlidBallTextureNormal(SLIDE_ROUND);
	sliderS->loadProgressBarTexture(SLIDE_BAR_PROGRESS);
	sliderS->setAnchorPoint(Vec2(0, 0.5));

	/*sliderS->setPosition(Vec2(mSfx->getPosition().x + mBackground->getContentSize().width / 12,
		mSfx->getPosition().y));*/
	sliderS->setPosition(Vec2(-mSfx->getContentSize().width/2,mSfx->getPosition().y));
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