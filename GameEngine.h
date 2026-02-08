#pragma once
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "BasicHeader.h"

class GameEngine
{
public:
	virtual void init();
	virtual void update();
	virtual void render();
	virtual void cleanup();
	virtual D3DXVECTOR2 getPosition();
	virtual void setPosition(D3DXVECTOR2 position);
};

#endif