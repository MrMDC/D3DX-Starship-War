#pragma once
#ifndef FONT_H
#define FONT_H

#include "MoreHeader.h"
#include "GameEngine.h"

class Font : public GameEngine
{
protected:
	LPCSTR text;
	int textWidth;
	int textHeight;
	int alignFormat;
	D3DCOLOR color;

	RECT textRect;

	// Font Transformation Variables
	D3DXMATRIX matrix;
	D3DXVECTOR2 position;

public:
	void init(LPCSTR text, D3DXVECTOR2 position, int textWidth, int textHeight, int alignFormat = DT_CENTER, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void render();

	D3DXVECTOR2 getPosition();

	void setText(LPCSTR text);
	void setSize(int textWidth, int textHeight);
	void setAlignFormat(int alignFormat);
	void setColor(D3DCOLOR color);
	void setPosition(D3DXVECTOR2 position);

	void cleanup();

	Font();
	~Font();
};

#endif