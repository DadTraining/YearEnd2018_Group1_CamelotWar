#include "Model.h"

Model::Model()
{
	
}

Model::Model(cocos2d::Scene * scene)
{

}



cocos2d::Vec2 Model::getPos()
{
	return mSprite->getPosition();
}

void Model::setPos(cocos2d::Vec2 pos)
{
	mSprite->setPosition(pos);
}

void Model::setAnimation(std::string namePlist, char* namePng, int CountImage,int speed, int repeat)
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	//add plist
	auto spritecache = cocos2d::SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(namePlist);
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;

	char str[100];
	for (int i = 0; i < CountImage; i++)
	{
		sprintf(str, namePng, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}

	//run action animation
	auto animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / speed);
	if (repeat == 1 )
	{
		mSprite->runAction(cocos2d::Animate::create(animation));
	}
	else
	{
		mSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation)));
	}
}


Model::~Model()
{

}
