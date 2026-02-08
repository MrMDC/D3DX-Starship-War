#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "MoreHeader.h"
#include "Level.h"
#include "Level1.h"
#include "Settings.h"

class MainMenu : public Level
{
protected:
	Sprite* startButton;
	Sprite* settingsButton;
	Sprite* exitButton;

public:
	void init();
	void update();
	void endGame();

	MainMenu();
	~MainMenu();
};

#endif