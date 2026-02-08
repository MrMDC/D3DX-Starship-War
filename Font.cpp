#include "Font.h"

void Font::init(LPCSTR text, D3DXVECTOR2 position, int textWidth, int textHeight, int alignFormat, D3DCOLOR color)
{
	//Initialize the font variables
	this->text = text;
	this->alignFormat = alignFormat;
	this->color = color;
	setPosition(position);
	setSize(textWidth, textHeight);
}

void Font::render()
{
	d3dManager->getSpriteBrush()->Begin(D3DXSPRITE_ALPHABLEND);

	//Define the matrix transformation of the font
	D3DXMatrixTransformation2D(&matrix, NULL, 0, NULL, NULL, 0, &position);
	//Get the sprite brush
	d3dManager->getSpriteBrush()->SetTransform(&matrix);
	//Draw out the text to the screen
	d3dManager->getFontBrush()->DrawText(d3dManager->getSpriteBrush(), text, -1, &textRect, alignFormat, color);
	//End the current sprite brush session
	d3dManager->getSpriteBrush()->End();
}

D3DXVECTOR2 Font::getPosition()
{
	return D3DXVECTOR2();
}

void Font::setText(LPCSTR text)
{
	this->text = text;
}

void Font::setSize(int textWidth, int textHeight)
{
	//Set the text dimension
	this->textWidth = textWidth;
	this->textHeight = textHeight;

	textRect.top = 0;
	textRect.left = 0;
	textRect.right = textRect.left + textWidth;
	textRect.bottom = textRect.top + textHeight;
}

void Font::setAlignFormat(int alignFormat)
{
	this->alignFormat = alignFormat;
}

void Font::setColor(D3DCOLOR color)
{
	this->color = color;
}

void Font::setPosition(D3DXVECTOR2 position)
{
	this->position = position;
}

void Font::cleanup()
{
}

Font::Font()
{
}

Font::~Font()
{
	cleanup();
}
