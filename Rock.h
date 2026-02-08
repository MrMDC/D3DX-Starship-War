#pragma once
#ifndef ROCK_H
#define ROCK_H

#include "MoreHeader.h"
#include "MoveableSprite.h"

class Rock : public MoveableSprite
{
protected:
	bool rockBreak;
	bool animateDone;

public:
	static int count;
	bool getRockBreak();
	bool getAnimateDone();

	void setRockBreak(bool rockBreak);
	void setAnimateDone(bool animateDone);

	void init();
	void update();

	void updateFrameLoop();
	void move();

	void animateInit();

	D3DXVECTOR2 randomPosition(int index);
	D3DXVECTOR2 randomForce();
	int randomMass();

	Rock();
};

#endif