#include "Model.h"
#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

Character::Character(cocos2d::Scene * scene)
{
	
}

void Character::update()
{
}

void Character::init()
{
}

void Character::deCreaseHP()
{
}

void Character::reBorn()
{
}

int Character::getHP()
{
	return mHP;
}

void Character::setHP(int hp)
{
	mHP = hp;
}

int Character::getPrice()
{
	return mPrice;
}

void Character::setPrice(int price)
{
	mPrice = price;
}

int Character::getDamage()
{
	return mDamage;
}

void Character::setDamage(int damage)
{
	mDamage = damage;
}

int Character::getSpeed()
{
	return mSpeed;
}

void Character::setSpeed(int speed)
{
	mSpeed = speed;
}
