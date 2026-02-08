#pragma once
#ifndef VICTORY_H
#define VICTORY_H

#include "MoreHeader.h"
#include "Level.h"

class Victory : public Level
{
protected:
	Sprite* backButton;

    void init();
    void update();

    ~Victory();
};

#endif