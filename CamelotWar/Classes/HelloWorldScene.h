#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Character.h"
#include <vector>

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);
	
	void createIconHero();

	void createMonster();

	void update(float delta);

    CREATE_FUNC(HelloWorld);
private:
	std::vector< Character*> mListCharacters;
	std::vector< Character*> mListMonsters;
	std::vector< cocos2d::Sprite*> mListIconHero;
	int mCountCharacter;
};

#endif // __HELLOWORLD_SCENE_H__
