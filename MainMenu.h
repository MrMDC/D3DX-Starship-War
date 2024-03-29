#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "MoreHeader.h"
#include "Level.h"

class MainMenu : public Level
{
protected:

public:
	void init();
	void update();
	void endGame();

	MainMenu();
	~MainMenu();
};

#endif