#include "Model.h"
#include "Boat.h"
#include "Defines.h"
#include "Character.h"

Boat::Boat(cocos2d::Scene *scene)
{
	init();
	scene->addChild(mSprite);

	lableCoin = cocos2d::Label::createWithTTF("", FONT_COIN, 20);
	lableCoin->setTextColor(cocos2d::Color4B::YELLOW);
	lableCoin->setPosition(cocos2d::Vec2(40, SCREEN_H - 50));
	scene->addChild(lableCoin,999);

	coin = 300;
	cocos2d::CCString *tempScore = cocos2d::CCString::createWithFormat("%i", coin);
	lableCoin->setString(tempScore->getCString());
} 

Boat::~Boat()
{
}

void Boat::update()
{
	collision();
	cocos2d::CCString *tempScore = cocos2d::CCString::createWithFormat("%i", coin);
	lableCoin->setString(tempScore->getCString());
}

void Boat::init()
{
	mSprite = cocos2d::Sprite::create(BOAT_NAME_SPRITE);
	setPos(cocos2d::Vec2(SCREEN_W / 2, BOAT_MIN_POSITION_Y));
}

void Boat::collision()
{
	for (int i = 0; i < mListMonsters.size(); i++)
	{
		if (mListMonsters[i]->getSprite()->getBoundingBox().intersectsRect(mSprite->getBoundingBox()))
		{
			//mListMonsters[i]->setPos(cocos2d::Vec2(mListMonsters[i]->getPos().x, SCREEN_H/2));
			mListMonsters[i]->reBorn();
		}
		for (int j = 0; j < mListMonsters[i]->getCoin().size(); j++)
		{
			if (mListMonsters[i]->getBoudingBoxCoin(j).intersectsRect(mSprite->getBoundingBox()))
			{
				int temp = mListMonsters[i]->getPrice();
				coin = coin + temp;
				mListMonsters[i]->setVisibleCoin(false, j);
				mListMonsters[i]->getCoin().at(j)->setPos(cocos2d::Vec2(SCREEN_W, SCREEN_H));
				mListMonsters[i]->getCoin().at(j)->setDynamic(false);
				mListMonsters[i]->getCoin().at(j)->setCheckFall(false);
				mListMonsters[i]->getCoin().at(j)->CoinPriceFly(mListMonsters[i]->getPrice(),cocos2d::Vec2(getPos().x,getPos().y + mSprite->getContentSize().height/2));
			}
		}
	}
}

int Boat::getcoin()
{
	return coin;
}

void Boat::setcoin(int acoin)
{
	coin = acoin;
}


void Boat::setListMonster(std::vector<Character*> listMonsters)
{
	mListMonsters = listMonsters;
}

void Boat::setListCharacter(std::vector<Character*> listCharacter)
{
	mListCharacter = listCharacter;
}

bool Boat::BoatTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (mSprite->getBoundingBox().containsPoint(touch->getLocation()))
	{
		return true;
	}
	return false;
}

void Boat::BoatTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (touch->getLocation().x < getPos().x)
	{
		mSprite->setFlipX(false);
	}
	else {
		mSprite->setFlipX(true);
	}
	if (touch->getLocation().x <= SCREEN_W - 100 && touch->getLocation().x > mSprite->getContentSize().width/2)
	{
		setPos(cocos2d::Vec2(touch->getLocation().x, BOAT_MIN_POSITION_Y));
	}
	
}

void Boat::BoatTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

