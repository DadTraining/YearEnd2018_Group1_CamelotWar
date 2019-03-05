#pragma once

#include "cocos2d.h"
#include "Model.h"
#include "Character.h"
class Pedestal : public Model
{
public:
	Pedestal();
	Pedestal(cocos2d::Scene *scene);
	~Pedestal();
	void update() override;
	int getBuffATK();
	void setBuffATK(int buff);
	int getBuffSpeed();
	void setBuffSpeed(int buff);
	int getBuffRange();
	void setBuffRange(int buff);
	void init() override;

	cocos2d::Rect getBoudingBox();

private:
	std::vector< Character*> mListCharacters;
	int buffATK;
	int buffSpeed;
	int buffRange;
};

