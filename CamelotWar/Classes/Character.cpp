#include "Model.h"
#include "Character.h"
#include "Defines.h"

Character::Character()
{

}

Character::~Character()
{

}

Character::Character(cocos2d::Scene * scene)
{
	for (int i = 0; i < 3; i++)
	{
		auto coin = new CoinModel(scene);
		coins.push_back(coin);
	}

	init();
	scene->addChild(mHpBar);
	scene->addChild(mloadingHpBar);
}

void Character::deCreaseHP(int hp)
{
	float percentHpDecrease =( (float) hp / (float)mHP) * 100;
	mloadingHpBar->setPercent(mloadingHpBar->getPercent() - percentHpDecrease);
}

void Character::reBorn()
{
	mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
	setPos(cocos2d::Vec2(getPos().x, SCREEN_H / 3 - mSprite->getContentSize().height));
	mloadingHpBar->setPercent(100);
	mAlive = 1;
	mDamage = mDamage * 2 ;
	mHP = mHP + 100;
	mSpeed = mSpeed * 2 ;

	if (mPhysicsBody != nullptr)
	{
		mPhysicsBody->setDynamic(false);
	}
}

void Character::setPosAll(cocos2d::Vec2 pos)
{
	setPos(pos);
	setPosHp(cocos2d::Vec2(pos.x, pos.y + mSprite->getContentSize().height + 10));
} 

void Character::init()
{
	mHpBar = cocos2d::Sprite::create("loading_bg.png");

	mloadingHpBar = cocos2d::ui::LoadingBar::create("loadingbar.png");
	mloadingHpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mloadingHpBar->setPercent(100);

	setVisibleHP(false);
	//coin
	for (int i = 0; i < 3; i++)
	{
		setVisibleCoin(false,i);
	}
	mAppear = false;
	mCheckAtk = false;
}

std::vector<CoinModel*> Character::getCoin()
{
	return coins;
}

int Character::getPrice()
{
	return mPrice;
}

void Character::setVisibleCoin(bool visible , int i)
{
	coins[i]->getSprite()->setVisible(visible);
}

void Character::setVisibleHP(bool visible)
{
	mHpBar->setVisible(visible);
	mloadingHpBar->setVisible(visible);
}

void Character::setAlive(int alive)
{
	mAlive = alive;
}

int Character::getAlive()
{
	return mAlive;
}

void Character::setCastle(Castle * castle)
{
	mCastle = castle;
}

void Character::setAppear(bool appear)
{
	mAppear = appear;
}

bool Character::getAppear()
{
	return mAppear;
}

cocos2d::Rect Character::getBoudingBoxCoin(int i)
{
	return coins[i]->getSprite()->getBoundingBox();
}

void Character::setcheckAppear(bool appear)
{
	checkAppear = appear;
	
}

bool Character::getcheckAppear()
{
	return checkAppear;
}

void Character::setCheckATK(bool checkATK)
{
	mCheckAtk = checkATK;
}

bool Character::getCheckATK()
{
	return  mCheckAtk;
}

void Character::setPosHp(cocos2d::Vec2 pos)
{
	mHpBar->setPosition(pos);
	mloadingHpBar->setPosition(pos);
}

void Character::addPhysicsBody()
{
	// Initialize physics body
	mPhysicsBody = cocos2d::PhysicsBody::createBox(mSprite->getContentSize(), cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f));
	mPhysicsBody->setDynamic(false);
	mPhysicsBody->setCategoryBitmask(false);
	mSprite->addComponent(mPhysicsBody);
}