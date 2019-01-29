#include "Model.h"

Model::Model()
{
}

Model::Model(cocos2d::Scene * scene)
{
}

cocos2d::Sprite * Model::getSprite()
{
	return mSprite;
}

void Model::setSprite(cocos2d::Sprite * sprite)
{
	mSprite = sprite;
}

cocos2d::Vec2 Model::getPos()
{
	return mSprite->getPosition();
}

void Model::setPos(cocos2d::Vec2 pos)
{
	mSprite->setPosition(pos);
}

void Model::setAnimation(std::string namePlist, char* namePng, int CountImage, cocos2d::Vec2 pos, cocos2d::Scene * scene)
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	//add plist
	auto spritecache = cocos2d::SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(namePlist);
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i < CountImage; i++)
	{
		sprintf(str, namePng, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	//create fist sprite
	mSprite = cocos2d::Sprite::createWithSpriteFrame(animFrames.front());
	scene->addChild(mSprite);
	//run action animation
	setPos(pos);
	auto animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / 8);
	mSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation)));
}


Model::~Model()
{
}
