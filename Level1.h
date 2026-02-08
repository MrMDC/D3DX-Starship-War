#pragma once
#ifndef LEVEL1_H
#define LEVEL1_H

#include "MoreHeader.h"
#include "Level.h"
#include "GameOver.h"
#include "Victory.h"
#include "Player.h"
#include "Rock.h"

class Level1 : public Level
{
protected:
	int timer;
	int counter;
	Player* player;
	vector<Rock*> rockList;
	Font* timerText;
	string timerTextString;
	LPCSTR timerTextLString;
	Font* rockRemain;
	string rockRemainString;
	LPCSTR rockRemainLString;

public:
	void init();
	void update();
	void updateText();
};

#endif