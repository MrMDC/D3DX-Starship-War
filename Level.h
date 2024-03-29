#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "MoreHeader.h"
#include "Sprite.h"

class Level : public Game
{
protected:
	vector<Sprite*> spriteList;
	//vector<Line*> lineList;
	//vector<Font*> fontList;

public:
	void input();
	void render();
	void cleanup();

	~Level();
};

#endif LEVEL_H