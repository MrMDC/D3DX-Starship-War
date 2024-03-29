#pragma once
#ifndef D3DMANAGER_H
#define D3DMANAGER_H

#include "BasicHeader.h"

class D3DManager
{
protected:
	// DirectX device
	IDirect3DDevice9* d3dDevice;

	// Brushes
	LPD3DXSPRITE spriteBrush;
	LPD3DXFONT fontBrush;
	LPD3DXLINE lineBrush;

	void init();

public:
	// Methods to get Brush
	IDirect3DDevice9* getDevice();
	LPD3DXSPRITE getSpriteBrush();
	LPD3DXFONT getFontBrush();
	LPD3DXLINE getLineBrush();

	void cleanup();

	D3DManager();
	~D3DManager();
};

#endif