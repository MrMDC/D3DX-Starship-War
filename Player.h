#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "MoveableSprite.h"

class Player : public MoveableSprite
{
protected:
	// Placeholder for hp
	int hp;

public:
	void init();
	void updateFrame();
	void updateMove();

	// Player hp mechanics
	int getHp();
	void damage();
	bool getIsDead();
};

#endif