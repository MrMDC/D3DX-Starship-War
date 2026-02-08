#pragma once
#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "MoreHeader.h"
#include "Level.h"

class GameOver : public Level
{
protected:
	Sprite* backButton;

public:
    void init();
    void update();

    ~GameOver();
};

#endif