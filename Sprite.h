#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "MoreHeader.h"
#include "GameEngine.h"

class Sprite : public GameEngine
{
protected:
	// Sprite Properties
	// Initialized Variables
	LPDIRECT3DTEXTURE9 texture;
	int textureWidth;
	int textureHeight;
	int spriteCol;
	int spriteRow;

	// Determined Variables
	int spriteWidth;
	int spriteHeight;
	float radius;

	// Color
	D3DCOLOR color;

	// Store frame properties of sprite sheet
	// Used for animations / changing sprites
	int currentFrame;
	int maxFrame;

	// Sprite RECT
	RECT spriteRect;

	// Sprite Transformation Variables
	D3DXMATRIX matrix;
	D3DXVECTOR2 scalingCenter;
	float scalingRotation;
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 rotationCenter;
	float defaultRotation;
	float rotation;
	D3DXVECTOR2 position;

	// Collision RECT (Used in collision detection)
	RECT colRect;

public:
	void init(LPCSTR address, int maxFrame, int textureWidth, int textureHeight, int spriteCol, int spriteRow);
	HRESULT setTexture(LPCSTR address);
	void setTextureData(int maxFrame, int textureWidth, int textureHeight, int spriteCol, int spriteRow);
	void SetColor(D3DCOLOR color);

	D3DXVECTOR2 getPosition();
	float getRadius();
	RECT getColRect();
	int getSpriteWidth();
	int getSpriteHeight();

	void setDefaultRotation(float defaultRotation);
	void setRotation(float rotation);
	void setScaling(D3DXVECTOR2 scaling);
	void SetScalingRotation(float scalingRotation);
	void SetPosition(D3DXVECTOR2 position);

	void render();

	void updateFrame();
	void updateFrameLoop();
	void updateFrameRect();

	void cleanup();

	~Sprite();
};

#endif