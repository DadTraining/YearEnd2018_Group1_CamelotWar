#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
<<<<<<< HEAD
#include "Archer.h"
=======
#include "Troll.h"

>>>>>>> 286ec8990016faf37db75f138831cf1d03ef8530
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

Archer* ARCHER;

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

<<<<<<< HEAD
=======
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	troll = new Troll(this);
>>>>>>> 286ec8990016faf37db75f138831cf1d03ef8530

	ARCHER = new Archer(this);
	ARCHER->init();
	scheduleUpdate();
	
    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	troll->setPos(cocos2d::Vec2(touch->getLocation()));
	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	troll->setPos(cocos2d::Vec2(touch->getLocation()));
}

void HelloWorld::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	troll->setPos(cocos2d::Vec2(touch->getLocation()));
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{

}

void HelloWorld::update(float delta)
{
<<<<<<< HEAD
	
	ARCHER->update();
=======
	//troll->update();
>>>>>>> 286ec8990016faf37db75f138831cf1d03ef8530
}