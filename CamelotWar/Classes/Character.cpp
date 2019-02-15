#include "Model.h"
#include "Character.h"

Character::Character()
{

}

Character::~Character()
{

}

Character::Character(cocos2d::Scene * scene)
{
	init();
	scene->addChild(mHpBar);
	scene->addChild(mloadingHpBar);
}

void Character::deCreaseHP()
{

}

void Character::reBorn()
{
}

void Character::update()
{
}

void Character::init()
{
	mHpBar = cocos2d::Sprite::create("loading_bg.png");

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mloadingHpBar->setPercent(100);

	mAlive = 1;
}

void Character::setPosHp(cocos2d::Vec2 pos)
{
	mHpBar->setPosition(pos);
	mloadingHpBar->setPosition(pos);
}

void Character::deCreaseHpBar()
{

}
