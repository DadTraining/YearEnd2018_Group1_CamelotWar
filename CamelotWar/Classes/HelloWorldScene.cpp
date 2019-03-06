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


USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto layout = HelloWorld::createWithPhysics();
	layout->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
	layout->getPhysicsWorld()->setGravity(cocos2d::Vec2(0, -980));

	auto scene = HelloWorld::create();
	layout->addChild(scene);

	return layout;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

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

	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SFX_WIN, false);

	auto background = cocos2d::Sprite::create(BACKGROUND_PLAYSCENE);
	background->setContentSize(visibleSize);
	background->setPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	addChild(background);

	popupSetting = PopUpSetting::create();
	this->addChild(popupSetting, 3);
	popupSetting->setVisible(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	mWinAndLose = cocos2d::Sprite::create();
	addChild(mWinAndLose,9999);

	createIconHero();

	createButtonSettings();

	createPedestal();

	countFrame = 0;
	indexCharacter = -1;

	boat = new Boat(this);
	boat->setListMonster(mListMonsters);

	mCastle = new Castle(this);

	check = 0;
	checkUpdate = true;
	checkAppearMonster = false;

	level = 1;
	monsterOfLevel(level);

	
	scheduleUpdate();

    return true;
}

void HelloWorld::createButtonSettings()
{
	mSetting = cocos2d::ui::Button::create("setting.png");
	mNext = cocos2d::ui::Button::create("next.png");
	mPause = cocos2d::ui::Button::create("pause.png");

	mSetting->setAnchorPoint(cocos2d::Vec2(1, 1));
	mNext->setAnchorPoint(cocos2d::Vec2(1, 1));
	mPause->setAnchorPoint(cocos2d::Vec2(1, 1));

	mSetting->setPosition(cocos2d::Vec2(SCREEN_W, SCREEN_H));
	mNext->setPosition(cocos2d::Vec2(mSetting->getPosition().x - mSetting->getContentSize().width, SCREEN_H));
	mPause->setPosition(cocos2d::Vec2(mSetting->getPosition().x - mSetting->getContentSize().width, SCREEN_H));
	
	mPause->setVisible(false);
	
	
	mSetting->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			popupSetting->setVisible(true);
			checkUpdate = false;
			break;
		default:
			break;
		}
	});

	mNext->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			mPause->setVisible(true);
			mNext->setVisible(false);
			checkAppearMonster = true;
			break;
		default:
			break;
		}
	});

	mPause->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			checkUpdate = false;
			mNext->setVisible(true);
			mPause->setVisible(false);
			break;
		default:
			break;
		}
	});

	addChild(mSetting);
	addChild(mNext);
	addChild(mPause);
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
				if (boat->getcoin() >= 100)
				{
					auto archer = new Archer(this);
					archer->setListMonster(mListMonsters);
					archer->setListPedestal(mListPedestal);
					archer->setPosAll(touch->getLocation());
					archer->setvisibleRange(true);
					archer->setPosRange();
					mListCharacters.push_back(archer);
					check = 1;
					boat->setcoin(boat->getcoin() - 100);
					break;
				}
				else
				{
					return false;
				}
			}
			case 1:
			{
				if (boat->getcoin() >= 200)
				{
					auto archer_knight = new Archer_knife(this);
					archer_knight->setListMonster(mListMonsters);
					archer_knight->setListPedestal(mListPedestal);
					archer_knight->setPosAll(touch->getLocation());
					archer_knight->setvisibleRange(true);
					archer_knight->setPosRange();
					mListCharacters.push_back(archer_knight);
					boat->setcoin(boat->getcoin() - 200);
					check = 1;
					break;
				}
				else
				{
					return false;
				}
			}
			case 2:
			{
				if (boat->getcoin() >= 300)
				{
					auto archer_fire = new Archer_Fire(this);
					archer_fire->setListMonster(mListMonsters);
					archer_fire->setListPedestal(mListPedestal);
					archer_fire->setPosAll(touch->getLocation());
					archer_fire->setvisibleRange(true);
					archer_fire->setPosRange();
					mListCharacters.push_back(archer_fire);
					boat->setcoin(boat->getcoin() - 300);
					check = 1;
					break;
				}
				else
				{
					return false;
				}
			}
			case 3:
			{
				if (boat->getcoin() >= 150)
				{
					auto axe_knight = new AxeKnight(this);
					axe_knight->setListMonster(mListMonsters);
					mListCharacters.push_back(axe_knight);
					boat->setcoin(boat->getcoin() - 150);	
					check = 0;
					break;
				}
				else
				{
					break;
				}
			}
			case 4:
			{
				if (boat->getcoin() >= 400)
				{
					auto spear_knight = new SpearKnight(this);
					spear_knight->setListMonster(mListMonsters);
					mListCharacters.push_back(spear_knight);
					boat->setcoin(boat->getcoin() - 400);
					check = 0;
					return false;
				}
				else
				{
					return false;
				}
			}
			case 5:
			{
				if (boat->getcoin() >= 9999)
				{
					auto sword_Knight = new SwordKnight(this);
					sword_Knight->setListMonster(mListMonsters);
					mListCharacters.push_back(sword_Knight);
					boat->setcoin(boat->getcoin() - 9999);
					check = 0;
					return false;
				}
				else
				{
					return false;
				}
			}
			}
			return true;
		}
	}
	if (boat->BoatTouchBegan(touch, event))
	{
		check = 2;
		return true;
	}
	else if (touchMonster(touch))
	{
		return true;
	}
	else if (touchCharacter(touch))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void HelloWorld::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (check == 1)
	{
		mListCharacters[mListCharacters.size() - 1]->setPos(touch->getLocation());
		mListCharacters[mListCharacters.size() - 1]->setPosRange();
	}
	if (check == 2)
	{
		boat->BoatTouchMoved(touch, event);
	}
}

void HelloWorld::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (check == 1)
	{
		mListCharacters[mListCharacters.size() - 1]->setAlive(1);
		mListCharacters[mListCharacters.size() - 1]->setcheckAppear(false);
		mListCharacters[mListCharacters.size() - 1]->setvisibleRange(false);
	}
	if(check > 2)
	{ 
		mListMonsters[check -3]->setVisibleHP(false);
	}
	if (indexCharacter != -1)
	{
		mListCharacters[indexCharacter]->setvisibleRange(false);
		indexCharacter = -1;
	}
}

bool HelloWorld::touchMonster(cocos2d::Touch * touch)
{
	for (int  i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getSprite()->getBoundingBox().containsPoint(touch->getLocation()))
		{
			mListMonsters[i]->setVisibleHP(true);
			check = i + 3;
			return true;
			break;
		}
		else
		{
			check = 0;
		}
	}
	if (check == 0)
	{
		return false;
	}
}

bool HelloWorld::touchCharacter(cocos2d::Touch * touch)
{
	for (int  i = 0; i < mListCharacters.size(); i++)
	{
		if (mListCharacters[i]->getSprite()->getBoundingBox().containsPoint(touch->getLocation()))
		{
			if (mListCharacters[i]->getpriceToUpLv() <= boat->getcoin() && mListCharacters[i]->getLvOfHero() < 3)
			{
				int newCoin = boat->getcoin() - mListCharacters[i]->getpriceToUpLv();
				boat->setcoin(newCoin);
				mListCharacters[i]->levleUp();
			}
			mListCharacters[i]->setvisibleRange(true);
			indexCharacter = i;
			return true;
		}
	}
	if (indexCharacter == -1)
	{
		return false;
	}

}

void HelloWorld::createIconHero()
{
	for (int i = 0; i < 6; i++)
	{
		char str[100];
		sprintf(str, "iconhero/hero%d.png", i+1);
		auto iconHero = cocos2d::Sprite::create(str);
		if (i==0)
		{
			float posX = iconHero->getContentSize().width / 2 + 80;
			float posY = SCREEN_H - iconHero->getContentSize().height / 2 - iconHero->getContentSize().height / 3 -5;
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

void HelloWorld::createMonster(int trolls, int hammerOrks, int hammerTrolls,int boneTrolls, int swordOrks, int axeOrks)
{
	for (int i = 0; i < trolls; i++)
	{
		Troll *troll = new Troll(this);
		troll->setCastle(mCastle);
		mListMonsters.push_back(troll);
	}
	for (int i = 0; i < hammerOrks; i++)
	{
		HammerOrk *hammerOrk = new HammerOrk(this);
		hammerOrk->setCastle(mCastle);
		mListMonsters.push_back(hammerOrk);
	}
	for (int i = 0; i < hammerTrolls; i++)
	{
		HammerTroll *hammerTroll = new HammerTroll(this);
		hammerTroll->setCastle(mCastle);
		mListMonsters.push_back(hammerTroll);
	}
	for (int i = 0; i < boneTrolls; i++)
	{
		BoneTroll *boneTroll = new BoneTroll(this);
		boneTroll->setCastle(mCastle);
		mListMonsters.push_back(boneTroll);
	}
	for (int i = 0; i < swordOrks; i++)
	{
		SwordOrk *swordOrk = new SwordOrk(this);
		swordOrk->setCastle(mCastle);
		mListMonsters.push_back(swordOrk);
	}
	for (int i = 0; i < axeOrks; i++)
	{
		AxeOrk *axeOrk = new AxeOrk(this);
		axeOrk->setCastle(mCastle);
		mListMonsters.push_back(axeOrk);
	}
	for (int  i = 0; i < mListMonsters.size(); i++)
	{
		mListMonsters[i]->setPos(cocos2d::Vec2(MONSTER_APPEAR, SCREEN_H / 3 - mListMonsters[i]->getSprite()->getContentSize().height));
	}
}

void HelloWorld::createPedestal()
{
	auto pedestal1 = new Pedestal(this);
	mListPedestal.push_back(pedestal1);
	pedestal1->setPos(cocos2d::Vec2(100, 350));

	auto pedestal2 = new Pedestal(this);
	mListPedestal.push_back(pedestal2);
	pedestal2->setBuffATK(2);
	pedestal2->setPos(cocos2d::Vec2(250, 500));

	auto pedestal3 = new Pedestal(this);
	mListPedestal.push_back(pedestal3);
	pedestal3->setPos(cocos2d::Vec2(450, 400));

	auto pedestal4 = new Pedestal(this);
	mListPedestal.push_back(pedestal4);
	pedestal4->setBuffRange(2);
	pedestal4->setPos(cocos2d::Vec2(650, 600));

	auto pedestal5 = new Pedestal(this);
	mListPedestal.push_back(pedestal5);
	pedestal5->setPos(cocos2d::Vec2(850, 350));

	auto pedestal6 = new Pedestal(this);
	mListPedestal.push_back(pedestal6);
	pedestal6->setBuffSpeed(2);
	pedestal6->setPos(cocos2d::Vec2(1050, 530));
}

void HelloWorld::checkDuplicate()
{
	if (mListCharacters.size() > 1)
	{
		for (int i = 0; i < mListCharacters.size()-1; i++)
		{
			if (mListCharacters[mListCharacters.size()-1]->getAlive() == 1 && !mListCharacters[mListCharacters.size() - 1]->getcheckAppear())
			{
				if (mListCharacters[mListCharacters.size() - 1]->getSprite()->getBoundingBox().intersectsRect(mListCharacters[i]->getSprite()->getBoundingBox()))
				{
					mListCharacters[mListCharacters.size() - 1]->setAlive(2);
					mListCharacters[mListCharacters.size() - 1]->setAppear(false);
					break;	
				}
			}
		}
		if (!mListCharacters[mListCharacters.size() - 1]->getcheckAppear())
		{
			mListCharacters[mListCharacters.size() - 1]->setcheckAppear(true);
		}
	}
}

void HelloWorld::update(float delta)
{
	if (checkUpdate)
	{
		myUpdate();
	}
	if (!popupSetting->isVisible() && mPause->isVisible())
	{
		checkUpdate = true;
	}
}

void HelloWorld::myUpdate()
{
	for (int i = 0; i < mListCharacters.size(); i++)
	{
		if (mListCharacters[i]->getAlive() == 1)
		{
			mListCharacters[i]->update();
			mListCharacters[i]->setPosRange();
		}
		if (mListCharacters[i]->getAlive() == 2 && !mListCharacters[i]->getAppear())
		{
			boat->setcoin(boat->getcoin() + mListCharacters[i]->getPrice());
			mListCharacters[i]->getSprite()->removeFromParent();
			mListCharacters.erase(mListCharacters.begin() + i);
		}
	}

	if (checkAppearMonster)
	{
		countFrame += 1;
		if (countFrame % (FPS) == 0)
		{
			for (int i = 0; i < mListMonsters.size(); i++)
			{
				if (mListMonsters[i]->getAppear() == false)
				{
					mListMonsters[i]->setAppear(true);
					countFrame = 0;
					break;
				}
			}
		}

		for (int i = 0; i < mListMonsters.size(); i++)
		{
			if (mListMonsters[i]->getAppear() == true)
			{
				mListMonsters[i]->update();
			}
		}
	}
	boat->update();
	checkDuplicate();

	//lose
	if (mCastle->getLoadingbar()->getPercent() == 0)
	{
		checkUpdate = false;
		mNext->setVisible(true);
		mPause->setVisible(false);
		mWinAndLose->setTexture(LOSE_SPRITE);
		mWinAndLose->setPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
		auto FadeIn = cocos2d::FadeIn::create(0.2);
		mWinAndLose->runAction(FadeIn);
	}

	int checkLevelUp = 0;
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getAlive() != 1 && mListMonsters[i]->getCheckFallDone())
		{
			checkLevelUp ++;
		}
	}
	if (checkLevelUp == mListMonsters.size() && level < 6)
	{
		level += 1;
		monsterOfLevel(level);
		mNext->setVisible(true);
		mPause->setVisible(false);
		mWinAndLose->setTexture(WIN_SPRITE);
		mWinAndLose->setPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
		auto FadeOut = cocos2d::FadeOut::create(0.2);
		auto FadeIn = cocos2d::FadeIn::create(0.2);
		auto sequence = cocos2d::Sequence::create(FadeOut, FadeIn, FadeOut->clone(), FadeIn->clone(), FadeOut->clone(), nullptr);
		mWinAndLose->runAction(sequence);

		
		
		checkAppearMonster = false;
	}
	//readd listmonster in character
	if (mListCharacters.size() >= 1)
	{
		for (int i = 0; i < mListCharacters.size(); i++)
		{
			mListCharacters[i]->setListMonster(mListMonsters);
		}
	}
	// win
	if (level > 5)
	{

	}
}

void HelloWorld::removeAllMonster()
{
	for (int  i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getAlive() != 1)
		{
			for (int j = 0; j < 3; j++)
			{
				mListMonsters[i]->getCoin().at(j)->removeCoin();
			}
			mListMonsters[i]->getSprite()->removeFromParent();
		}
	}
	mListMonsters.erase(mListMonsters.begin(), mListMonsters.end());
}

void HelloWorld::monsterOfLevel(int level)
{
	switch (level)
	{
	case 1:
	{
		removeAllMonster();
		createMonster(3, 3, 0, 0, 0, 0);
		boat->setListMonster(mListMonsters);
		break;
	}
	case 2:
	{
		removeAllMonster();
		createMonster(5, 0, 3, 0, 0, 0);
		boat->setListMonster(mListMonsters);
		break;
	}
	case 3:
	{
		removeAllMonster();
		createMonster(5,0,4,2,0,0);
		boat->setListMonster(mListMonsters);
		break;
	}
	case 4:
	{
		removeAllMonster();
		createMonster(3, 5, 3, 0, 2, 0);
		boat->setListMonster(mListMonsters);
		break;
	}
	case 5:
	{
		removeAllMonster();
		createMonster(0, 5, 0, 4, 4, 0);
		boat->setListMonster(mListMonsters);
		break;
	}
	default:
		break;
	}
}