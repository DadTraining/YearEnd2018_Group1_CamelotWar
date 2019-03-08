#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Character.h"
#include "pedestal.h"
#include "Boat.h"
#include "Castle.h"
#include "Setting.h"
#include <vector>
#include "PopUpGameOver.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void createButtonSettings();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

	bool touchMonster(cocos2d::Touch * touch);

	bool touchCharacter(cocos2d::Touch * touch);
	
	void createIconHero();

	void createMonster(int troll, int hammerOrk, int hammerTroll, int boneTroll, int swordOrk, int axeOrk);

	void createPedestal();

	void checkDuplicate();

	void update(float delta);

	void myUpdate();

	void removeAllMonster();

	void monsterOfLevel(int level);

	void MonsterAppear();

	void updateCharacter();

	void checkWinGame();

	void checkLose();

	void levleUp();

    CREATE_FUNC(HelloWorld);
	

private:
	std::vector< Character*> mListCharacters;
	std::vector< Character*> mListMonsters;
	std::vector< cocos2d::Sprite*> mListIconHero;
	std::vector< Pedestal*> mListPedestal;
	cocos2d::ui::Button * mNext;
	cocos2d::ui::Button * mPause;
	cocos2d::ui::Button * mSetting;
	cocos2d::ui::Button * mBtUpHero;
	cocos2d::Sprite * mWinAndLose;

	Setting * popupSetting;
	PopUpGameOver * popupGameOver;

	Boat *boat;
	Castle * mCastle;
	int check;
	int countFrame;
	int indexCharacter;
	int level;
	bool checkUpdate;
	bool checkAppearMonster;
	bool checkEnableBt;
};

#endif // __HELLOWORLD_SCENE_H__
