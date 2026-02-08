#pragma once
#ifndef LINE_H
#define LINE_H

#include "MoreHeader.h"
#include "GameEngine.h"

class Line : GameEngine
{
protected:
	int verticeNum;
	D3DXVECTOR2* vertices;
	D3DCOLOR color;

public:
	void initLine(int verticeNum, D3DXVECTOR2 vertices[], D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void setColor();
	void render();

	void cleanup();

	// Template function
	// Creates a star at the center position 
	void createStar(D3DXVECTOR2 position, int size);

	Line();
	~Line();
};

#endif