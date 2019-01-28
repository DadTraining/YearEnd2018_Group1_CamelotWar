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


Model::~Model()
{
}
