#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "MoreHeader.h"
#include "Sprite.h"
#include "Line.h"
#include "Font.h"

class Level : public Game
{
protected:
	vector<Sprite*> spriteList;
	vector<Line*> lineList;
	vector<Font*> fontList;
	bool showCursor = false;
	Sprite* cursor;

public:
	void input();
	void render();
	void cleanup();
	void updateCursor();

	~Level();
};

#endif LEVEL_H