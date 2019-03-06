#include "Archer.h"
#include "Defines.h"
#include "Character.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
Archer::Archer()
{
}

Archer::~Archer()
{
}

Archer::Archer(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER);
	//setPos(cocos2d::Vec2(SCREEN_W /2 , SCREEN_H -100));
	scene->addChild(mSprite);
	mSprite->setFlipX(false);

	for (int i = 0; i < 10; i++)
	{
		auto arrow = new Arrow(scene);
		//arrow->setPos(cocos2d::Vec2(getPos().x , getPos().y));
		arrows.push_back(arrow);
		arrow->setVisible(false);
	}
	init();
}

void Archer::walk()
{
}

void Archer::attack()
{
	
}

void Archer::die()
{
}

void Archer::flip(bool flip)
{
	mSprite->setFlipX(flip);
}

void Archer::turnOnArrow(cocos2d::Vec2 pos)
{
	mFrameCount++;
	int a = (COUNT_IMG_ARCHER_ATTACK * FPS) / mSpeed;
	if (mFrameCount % a == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (arrows[i]->isVisible() == false)
			{
				if (mSprite->isFlipX() == false)
				{
					arrows[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width/2 , getPos().y));
				}
				else
				{
					arrows[i]->setPos(cocos2d::Vec2(getPos().x - mSprite->getContentSize().width / 2 , getPos().y));
				}
				arrows[i]->setVisible(true);
				arrows[i]->setMShoot(mSprite->isFlipX());
				arrows[i]->fly(pos);
				break;
			}
		}
	}
}

void Archer::shootArrow()
{
	for (int i = 0; i < 10; i++)
	{
		if (arrows[i]->isVisible() == true)
		{
			arrows[i]->update();
			
		}
	}
}

void Archer::collision()
{
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		for (int j = 0; j < arrows.size(); j++)
		{	
			if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(arrows[j]->getSprite()->getBoundingBox()))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_ARCHERY, false, 1.0f, 1.0f, 1.0f);
				mListMonsters[i]->deCreaseHP(mDamage);
				arrows[j]->setVisible(false);
				arrows[j]->setPos(cocos2d::Vec2(getPos().x, getPos().y));
			}
		}
	}
}

void Archer::reuseArrow()
{
	for (int i = 0; i < 10; i++)
	{
		if (arrows[i]->getPos().y <= SCREEN_H/3)
		{
			arrows[i]->setVisible(false);
		}
	}
}

void Archer::setListMonster(std::vector< Character*> listMonsters)
{
	mListMonsters = listMonsters;
}

void Archer::setListPedestal(std::vector<Pedestal*> listPedestals)
{
	mListPedestals = listPedestals;
}

void Archer::update()
{ 
	
	for (int j = 0;j < mListMonsters.size(); j++)
	{
		if (mListMonsters[j]->getAlive() == 1)
		{
			if (mListMonsters[j]->getPos().x >= getPos().x - mRange && mListMonsters[j]->getPos().x <= getPos().x)
			{
				mSprite->setFlipX(true);
				turnOnArrow(mListMonsters[j]->getPos());
				if (changeStatus == 0)
				{
					setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK, COUNT_IMG_ARCHER_ATTACK, mSpeed, 0);
					changeStatus = 1;
				}
				break;
			}
			else if (mListMonsters[j]->getPos().x >= getPos().x  && mListMonsters[j]->getPos().x <= getPos().x + mRange)
			{
				mSprite->setFlipX(false);
				turnOnArrow(mListMonsters[j]->getPos());
				if (changeStatus == 0)
				{
					setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK, COUNT_IMG_ARCHER_ATTACK, mSpeed, 0);
					changeStatus = 1;
				}
				break;
			}
		}
	    if (j == mListMonsters.size()-1)
		{
			mSprite->stopAllActions();
			changeStatus = 0;
		}
	}
	
	reuseArrow();
	shootArrow();
	collision();
	collisionWithPedestal();
	setPosAll(getPos());
	
}

void Archer::init()
{
	mSpeed = 20;
	mRange = 100;
	mDamage = 15;
	mPrice = 100;
	priceToUpLv = 100;

	mFrameCount = 0;
	changeStatus = 0;
	hasAnimated = false;
	// setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK, COUNT_IMG_ARCHER_ATTACK, mSpeed, 0);
}	

void Archer::collisionWithPedestal()
{
	for (int i = 0; i < mListPedestals.size(); i++)
	{
		if (mListPedestals[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()))
		{

			mAppear = true;
			mSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
			setPos(cocos2d::Vec2(getPos().x, mListPedestals[i]->getPos().y +mListPedestals[i]->getSprite()->getContentSize().height/2 - 10));
			if (!checkBuff)
			{
				mDamage = mDamage * mListPedestals[i]->getBuffATK();
				mSpeed = mSpeed * mListPedestals[i]->getBuffSpeed();
				mRange = mRange * mListPedestals[i]->getBuffRange();
				checkBuff = true;
			}
			break;
		}
	}
	if (!mAppear)
	{
		setAlive(2);
	}
}