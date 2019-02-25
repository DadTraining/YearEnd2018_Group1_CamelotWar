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
Archer_Fire * archer_fire;
Archer_knife * archer_knife;

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

	createMonster();

	archer = new Archer(this);
	archer->setListMonster(mListMonsters);

	archer_fire = new Archer_Fire(this);
	archer_fire->setListMonster(mListMonsters);

	archer_knife = new Archer_knife(this);
	archer_knife->setListMonster(mListMonsters);

	scheduleUpdate();
	
    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void HelloWorld::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void HelloWorld::createMonster()
{
	Troll *troll = new Troll(this);
	mListMonsters.push_back(troll);
}


void HelloWorld::update(float delta)
{	
	archer->update();
	archer_fire->update();
	archer_knife->update();
	for (int  i = 0; i < mListMonsters.size(); i++)
	{
		mListMonsters[i]->update();
	}







}