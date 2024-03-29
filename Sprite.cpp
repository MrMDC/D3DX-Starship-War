#include "Sprite.h"

void Sprite::init(LPCSTR address, int maxFrame, int textureWidth, int textureHeight, int spriteCol, int spriteRow)
{
	setTexture(address);
	setTextureData(maxFrame, textureWidth, textureHeight, spriteCol, spriteRow);
}

HRESULT Sprite::setTexture(LPCSTR address)
{
	this->color = D3DCOLOR_XRGB(255, 255, 255);
	return D3DXCreateTextureFromFile(d3dManager->getDevice(), address, &texture);
}

void Sprite::setTextureData(int maxFrame, int textureWidth, int textureHeight, int spriteCol, int spriteRow)
{
	this->maxFrame = maxFrame;
	this->textureWidth = textureWidth;
	this->textureHeight = textureHeight;
	this->spriteCol = spriteCol;
	this->spriteRow = spriteRow;

	this->spriteWidth = textureWidth / spriteCol;
	this->spriteHeight = textureHeight / spriteRow;
	this->radius = spriteWidth / 2;

	spriteRect.left = 0;
	spriteRect.top = 0;
	spriteRect.right = spriteRect.left + spriteWidth;
	spriteRect.bottom = spriteRect.top + spriteHeight;

	scalingCenter = D3DXVECTOR2(0, 0);
	scaling = D3DXVECTOR2(1, 1);
	rotationCenter = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
}

void Sprite::SetColor(D3DCOLOR color)
{
	this->color = color;
}

D3DXVECTOR2 Sprite::getPosition()
{
	return position;
}

float Sprite::getRadius()
{
	return radius;
}

RECT Sprite::getColRect()
{
	return colRect;
}

int Sprite::getSpriteWidth()
{
	return spriteWidth;
}

int Sprite::getSpriteHeight()
{
	return spriteHeight;
}

void Sprite::setDefaultRotation(float defaultRotation)
{
	this->defaultRotation = defaultRotation;
}

void Sprite::setRotation(float rotation)
{
	this->rotation = rotation;
}

void Sprite::setScaling(D3DXVECTOR2 scaling)
{
	this->scaling = scaling;

	spriteHeight *= scaling.y;
	spriteWidth *= scaling.x;

	colRect.top = position.y;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;
	colRect.bottom = colRect.top + spriteHeight;

	radius = spriteWidth / 2;
}

void Sprite::SetScalingRotation(float scalingRotation)
{
	this->scalingRotation = scalingRotation;
}

void Sprite::SetPosition(D3DXVECTOR2 position)
{
	this->position = position;

	colRect.top = position.y;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;
	colRect.bottom = colRect.top + spriteHeight;
}

void Sprite::render()
{
	d3dManager->getSpriteBrush()->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMatrixTransformation2D(&matrix, &scalingCenter, scalingRotation, &scaling, &rotationCenter, defaultRotation + rotation, &position);
	d3dManager->getSpriteBrush()->SetTransform(&matrix);
	d3dManager->getSpriteBrush()->Draw(texture, &spriteRect, NULL, NULL, color);

	d3dManager->getSpriteBrush()->End();
}

void Sprite::updateFrame()
{
	updateFrameLoop();
	updateFrameRect();
}

void Sprite::updateFrameLoop()
{
	currentFrame = (currentFrame + 1) % maxFrame;
}

void Sprite::updateFrameRect()
{
	spriteRect.left = currentFrame % maxFrame % spriteCol * spriteWidth;
	spriteRect.top = currentFrame % maxFrame / spriteCol * spriteHeight;
	spriteRect.right = spriteRect.left + spriteWidth;
	spriteRect.bottom = spriteRect.top + spriteHeight;

	colRect.top = position.y;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;
	colRect.bottom = colRect.top + spriteHeight;
}

void Sprite::cleanup()
{
	if (texture != NULL) {
		texture->Release();
		texture = NULL;
	}
}

Sprite::~Sprite()
{
	cleanup();
}
