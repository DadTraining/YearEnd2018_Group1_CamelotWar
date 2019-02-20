#include "Archer.h"
#include "Defines.h"
#include "Character.h"



Archer::Archer()
{
}


Archer::~Archer()
{
}

Archer::Archer(cocos2d::Scene * scene) : Character::Character(scene)
{
	mSprite = cocos2d::Sprite::create(NAME_SPRITE_ARCHER);
	setPos(cocos2d::Vec2(SCREEN_W /2 , SCREEN_H -100));
	scene->addChild(mSprite);
	
	mSprite->setFlipX(false);

	for (int i = 0; i < 10; i++)
	{
		auto arrow = new Arrow(scene);
		arrow->setPos(cocos2d::Vec2(getPos().x , getPos().y));
		arrows.push_back(arrow);
		arrow->setVisible(false);
	}

	

	init();
}

void Archer::walk()
{
}

void Archer::attack()
{
}

void Archer::die()
{
}

void Archer::flip(boolean flip)
{
	mSprite->setFlipX(flip);
}

void Archer::turnOnArrow(cocos2d::Vec2 pos)
{
	mFrameCount++;
	int a = (COUNT_IMG_ARCHER_ATTACK * FPS) / mSpeed;
	if (mFrameCount % a == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (arrows[i]->isVisible() == false)
			{
				if (mSprite->isFlipX() == false)
				{
					arrows[i]->setPos(cocos2d::Vec2(getPos().x + mSprite->getContentSize().width, getPos().y));
				}
				else
				{
					arrows[i]->setPos(cocos2d::Vec2(getPos().x - mSprite->getContentSize().width, getPos().y));
				}
				arrows[i]->setVisible(true);
				arrows[i]->setMShoot(mSprite->isFlipX());
				arrows[i]->fly(pos);
				break;
			}
		}
	}
}

void Archer::shootArrow()
{
	for (int i = 0; i < 10; i++)
	{
		if (arrows[i]->isVisible() == true)
		{
			arrows[i]->update();
			
		}
	}
}

void Archer::collision()
{
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		for (int j = 0; j < arrows.size(); j++)
		{
			if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(arrows[j]->getSprite()->getBoundingBox()))
			{
				mListMonsters[i]->deCreaseHP(100);
				arrows[j]->setVisible(false);
				arrows[j]->setPos(cocos2d::Vec2(getPos().x, getPos().y));
			}
		}
	}
}

void Archer::reuseArrow()
{
	for (int i = 0; i < 10; i++)
	{
		if (arrows[i]->getPos().y <= mListMonsters[0]->getPos().y)
		{
			arrows[i]->setVisible(false);
		}
	}
}

void Archer::setListMonster(std::vector< Character*> listMonsters)
{
	for (int i = 0; i < listMonsters.size(); i++)
	{
		mListMonsters.push_back(listMonsters[i]);
	}
}
void Archer::update()
{ 
	
	for (int j = 0;j < mListMonsters.size(); j++)
	{
		if (mListMonsters[j]->getPos().x >= getPos().x - mRange && mListMonsters[j]->getPos().x <= getPos().x)
		{
			mSprite->setFlipX(true);
			turnOnArrow(mListMonsters[j]->getPos());
		}
		if (mListMonsters[j]->getPos().x >= getPos().x  && mListMonsters[j]->getPos().x <= getPos().x + mRange)
		{
			mSprite->setFlipX(false);
			turnOnArrow(mListMonsters[j]->getPos());
		}
	}
	reuseArrow();
	shootArrow();
	collision();
}

void Archer::init()
{
	mFrameCount = 0;
	mSpeed = 5;
	mRange = 300;
	mHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));
	mloadingHpBar->setPosition(cocos2d::Vec2(getPos().x, getPos().y + mSprite->getContentSize().height / 2));

	setAnimation(NAME_PLIST_ARCHER_ATTACK, NAME_PNG_ARCHER_ATTACK, COUNT_IMG_ARCHER_ATTACK,mSpeed,0);

}	