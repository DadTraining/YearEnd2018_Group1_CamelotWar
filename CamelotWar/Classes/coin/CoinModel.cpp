#include "CoinModel.h"
#include "DefineCoin.h"
#include "Defines.h"
#include "utils/animation/GetAnimation.h"
#include "utils/physics/CustomPhysicsBody.h"

CoinModel::CoinModel(cocos2d::Scene* scene) : Model()
{
    init();
    scene->addChild(mSprite, 5);
	scene->addChild(lable, 100000);
}

CoinModel::CoinModel(cocos2d::Node* node) : Model()
{
    init();
    node->addChild(mSprite, 5);
}

CoinModel::~CoinModel()
{
    // Destrucltor
}

void CoinModel::removeCoin()
{
	mSprite->removeFromParent();
	lable->stopAllActions();
	lable->removeFromParent();
}

void CoinModel::init()
{
    auto getAnimation = GetAnimation::GetInstance();
    mSpriteFrames = getAnimation->GetSpriteFramesWidthPlistFile(COIN_PLIST_NAME_PATH, COIN_NAME_FRAME_FORMAT, 10);
    
    mSprite = cocos2d::Sprite::createWithSpriteFrame(mSpriteFrames.front());
	mSprite->setTag(COIN_TAG);
	mSprite->runAction(GetAnimation::GetInstance()->GetAnimationRepeatForever(mSpriteFrames));

    CustomPhysicsBody::getInstance()->parseJsonFile(COIN_PHYSICS_JSON);
	mPhysicsBody = CustomPhysicsBody::getInstance()->bodyFormJson(mSprite, COIN_PHYSICS_NAME, cocos2d::PhysicsMaterial( 1, 1, 0 ));

    if (mPhysicsBody != nullptr)
    {
		mPhysicsBody->setCollisionBitmask(COIN_COLLISION_BITMASK);
		mPhysicsBody->setCategoryBitmask(1);
		mPhysicsBody->setContactTestBitmask(false);

        mSprite->setPhysicsBody(mPhysicsBody);
    }

	lable = cocos2d::Label::createWithSystemFont("", FONT_COIN, 20);
	lable->setTextColor(cocos2d::Color4B::YELLOW);
	mCheckFall = false;
}

void CoinModel::CoinPriceFly(int price , cocos2d::Vec2 pos)
{
	cocos2d::CCString *tempScore = cocos2d::CCString::createWithFormat("+ %i", price);
	lable->setString(tempScore->getCString());
	lable->setPosition(pos);
	auto moveUp = cocos2d::MoveBy::create(1, cocos2d::Vec2(0, 100));
	auto FadeOut = cocos2d::FadeOut::create(1);
	auto sequence = cocos2d::Sequence::create(moveUp, FadeOut, nullptr);
	lable->runAction(sequence);
}

void CoinModel::update()
{
	// Update function
}

void CoinModel::PushCoin(cocos2d::Vec2 velocity)
{
	mSprite->getPhysicsBody()->setVelocity(velocity);
}

void CoinModel::setDynamic(bool dynamic)
{
	mSprite->getPhysicsBody()->setDynamic(dynamic);
}

void CoinModel::setCheckFall(bool checkfall)
{
	mCheckFall = checkfall;
}

bool CoinModel::getCheckFall()
{
	return mCheckFall;
}
void CoinModel::removePhysics()
{
	mPhysicsBody->removeFromWorld();
	auto removeSelf = cocos2d::RemoveSelf::create();
	mSprite->runAction(removeSelf);
}