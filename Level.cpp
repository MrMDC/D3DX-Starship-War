#include "Level.h"

void Level::input()
{
	//Read the input
	inputManager->readInput();
}

void Level::render()
{
	//Start the D3DDevice and begin scening
	d3dManager->getDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dManager->getDevice()->BeginScene();

	int vectorSize;

	//Draw out all the sprites
	vectorSize = spriteList.size();
	for (int i = 0; i < vectorSize; i++) {
		spriteList.at(i)->render();
	}

	//Draw out all the texts
	vectorSize = fontList.size();
	for (int i = 0; i < vectorSize; i++) {
		fontList.at(i)->render();
	}

	//Draw out all the lines
	vectorSize = lineList.size();
	for (int i = 0; i < vectorSize; i++) {
		lineList.at(i)->render();
	}
	
	if (showCursor) cursor->render();

	//End the scening and present the sprites on screen
	d3dManager->getDevice()->EndScene();
	d3dManager->getDevice()->Present(NULL, NULL, NULL, NULL);
}

void Level::cleanup()
{
	int vectorSize;

	//Clean all the sprites presented
	vectorSize = spriteList.size();
	for (int i = 0; i < vectorSize; i++) {
		spriteList.at(spriteList.size() - 1)->cleanup();
		spriteList.pop_back();
	}

	//Clean all the texts presented
	vectorSize = fontList.size();
	for (int i = 0; i < vectorSize; i++) {
		fontList.at(fontList.size() - 1)->cleanup();
		fontList.pop_back();
	}

	//Clean all the lines presented
	vectorSize = lineList.size();
	for (int i = 0; i < vectorSize; i++) {
		lineList.at(lineList.size() - 1)->cleanup();
		lineList.pop_back();
	}

	//If the cursor presents, cleanup it
	if (showCursor) cursor->cleanup();
}

void Level::updateCursor()
{
	//Update the cursor position for every frame
	D3DXVECTOR2 mousePos = inputManager->getMousePosition();
	cursor->setPosition(mousePos);
}

Level::~Level()
{
	//Cleanup all the resources
	cleanup();
}
