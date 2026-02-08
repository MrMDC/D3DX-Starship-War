#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include "MoreHeader.h"
#include "Level.h"

class Settings : public Level
{
protected:
	Sprite* backButton;
	Sprite* addButton1;
	Sprite* minusButton1;
	Sprite* addButton2;
	Sprite* minusButton2;

public:
	void init();
	void update();
	string bgmVolumn;
	string effectVolumn;
	LPCSTR bgmVolumnFinal;
	LPCSTR effectVolumnFinal;

	Settings();
	~Settings();

};

#endif