#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

    void menuCloseCallback(cocos2d::Ref* pSender);
	void setPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
	void update(float delta);

    CREATE_FUNC(HelloWorld);
private:
	cocos2d::PhysicsWorld* sceneWorld;
};

#endif // __HELLOWORLD_SCENE_H__
