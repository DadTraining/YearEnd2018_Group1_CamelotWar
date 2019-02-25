#include "pedestal.h"
#include "Defines.h"

Pedestal::Pedestal()
{
}

Pedestal::Pedestal(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_PEDESTAL);
	setPos(cocos2d::Vec2(250,250));
	scene->addChild(mSprite);
}

void Pedestal::setlistCharacter(std::vector< Character*> listCharacters)
{
	mListCharacters = listCharacters;
}

void Pedestal::collision()
{
	for (int  i = 0; i < mListCharacters.size(); i++)
	{
		if (mListCharacters[i]->getAlive() == 1)
		{
			if (!mListCharacters[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()))
			{
				mListCharacters[i]->setAlive(2);
				
				break;
			}
		}
	}
}

Pedestal::~Pedestal()
{
}


void Pedestal::update()
{
	collision();
}

void Pedestal::init()
{
}
