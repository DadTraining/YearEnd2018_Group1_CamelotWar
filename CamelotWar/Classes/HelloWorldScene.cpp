#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Archer.h"
#include "Troll.h"
#include "HammerTroll.h"
#include "Defines.h"
#include "Archer_knife.h"
#include "Archer_Fire.h"
#include "BoneTroll.h"
#include "HammerOrk.h"
#include "SwordOrk.h"
#include "AxeOrk.h"
#include "SpearKnight.h"
#include "AxeKnight.h"
#include "SwordKnight.h"
#include "Boat.h"
#include "pedestal.h"
#include "Castle.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

Archer *archer;
Archer* ARCHER;
Troll * troll;
HammerTroll* hammerTroll;
Archer_knife *archer_knife;
Archer_Fire * archer_fire;
BoneTroll* boneTroll;
HammerOrk* hammerOrk;
SwordOrk* swordOrk;
AxeOrk* axeOrk;
SpearKnight* spearKnight;
AxeKnight* axeKnight;
SwordKnight* swordKnight;
Boat* boat;

Archer_knife * archer_knife;
Castle* castle;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	countFrame = 0;


	troll = new Troll(this);
	hammerTroll = new HammerTroll(this);
	boneTroll = new BoneTroll(this);
	hammerOrk = new HammerOrk(this);
	swordOrk = new SwordOrk(this);
	axeOrk = new AxeOrk(this);
	// boat
	boat = new Boat(this);
	boat->setListMonster(mListMonsters);

	check = true;


	createMonster();

	createIconHero();
	
	scheduleUpdate();
	

	//
	castle = new Castle(this);

	scheduleUpdate();
	
    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{



	for (int i = 0; i < mListIconHero.size(); i++)
	{
		if (mListIconHero[i]->getBoundingBox().containsPoint(touch->getLocation()))
		{
			switch (i)
			{
				case 0:
				{
					auto archer = new Archer(this);
					archer->setListMonster(mListMonsters);
					archer->setPosAll(touch->getLocation());
					mListCharacters.push_back(archer);
					check = true;
					break;
				}
				case 1:
				{
					auto archer_knight = new Archer_knife(this);
					archer_knight->setListMonster(mListMonsters);
					archer_knight->setPosAll(touch->getLocation());
					mListCharacters.push_back(archer_knight);
					break;
				}
				case 2:
				{
					auto archer_fire = new Archer_Fire(this);
					archer_fire->setListMonster(mListMonsters);
					archer_fire->setPosAll(touch->getLocation());
					mListCharacters.push_back(archer_fire);
					break;
				}
				case 6:
				{
					auto pedestal = new Pedestal(this);
					pedestal->setPos(touch->getLocation());
					pedestal->setlistCharacter(mListCharacters);
					mListPedestal.push_back(pedestal);
					check = false;
					break;
				}
				default: 
				{
					check = false;
					break;
				}
			}
			return true;
		}
	}
	return boat->BoatTouchBegan(touch, event);;

}

void HelloWorld::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{

	boat->BoatTouchMoved(touch, event);

	if (check)
	{
		mListCharacters[mListCharacters.size() - 1]->setPos(touch->getLocation());
	}
	else
	{
		//mListPedestal[mListPedestal.size() - 1]->setPos(touch->getLocation());
	}

}

void HelloWorld::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (check)
	{
		mListCharacters[mListCharacters.size() - 1]->setAlive(1);
	}
}

void HelloWorld::createIconHero()
{
	for (int i = 0; i < 7; i++)
	{
		char str[100];
		sprintf(str, "iconHero/%d.png", i+1);
		auto iconHero = cocos2d::Sprite::create(str);
		if (i==0)
		{
			float posX = iconHero->getContentSize().width / 2;
			float posY = SCREEN_H - iconHero->getContentSize().height / 2;
			iconHero->setPosition(cocos2d::Vec2(posX,posY));
		}
		else
		{
			float posX = mListIconHero[i - 1]->getPosition().x + mListIconHero[i - 1]->getContentSize().width/2 + iconHero->getContentSize().width / 2;
			float posY = mListIconHero[i - 1]->getPosition().y;
			iconHero->setPosition(cocos2d::Vec2(posX, posY));
		}
		mListIconHero.push_back(iconHero);
		addChild(iconHero);
	}
}

void HelloWorld::createMonster()
{
	for (int i = 0; i < 5; i++)
	{
		Troll *troll = new Troll(this);
		mListMonsters.push_back(troll);
	}
}



void HelloWorld::update(float delta)
{	
	countFrame += 1;
	for (int i = 0; i < mListCharacters.size(); i++)
	{
		if (mListCharacters[i]->getAlive() == 1)
		{
			mListCharacters[i]->update();
		}
		if (mListCharacters[i]->getAlive() == 2)
		{
			mListCharacters[i]->getSprite()->removeFromParent();
			mListCharacters.erase(mListCharacters.begin() + i);
		}
		CCLOG("%d", mListCharacters.size());
	archer->update();
	archer_fire->update();
	archer_knife->update();
	
	for (int  i = 0; i < mListMonsters.size(); i++)
	{
		mListMonsters[i]->update();
	}

	if (countFrame % FPS == 0)
	{
		for (int i = 0; i < mListMonsters.size(); i++)
		{
			if (mListMonsters[i]->getAppear() == false)
			{
				mListMonsters[i]->setAppear(true);
				CCLOG("%d", countFrame);
				countFrame =0;
				break;
			}
		}
	}

	for (int  i = 0; i <  mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getAppear() == true)
		{
			//CCLOG("ok");
			mListMonsters[i]->update();
		}
	}

	for (int i = 0; i < mListPedestal.size(); i++)
	{
		mListPedestal[i]->update();
		mListPedestal[i]->setlistCharacter(mListCharacters);
	}


	/*ARCHER->update();*/
	//troll->update();
	//hammerTroll->update();
	//boneTroll->update();
	//hammerOrk->update();
	//archer_knife->update();
	//archer_fire->update();
	//swordOrk->update();
	//axeOrk->update();
	boat->update();

}