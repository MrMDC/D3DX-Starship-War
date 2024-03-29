#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

class Game
{
public:
	virtual void init();
	virtual void input();
	virtual void update();
	virtual void render();
	virtual void cleanup();
};

#endif