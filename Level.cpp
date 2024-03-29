#include "Level.h"

void Level::input()
{
	inputManager->readInput();
}

void Level::render()
{
	d3dManager->getDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dManager->getDevice()->BeginScene();

	int vectorSize;

	vectorSize = spriteList.size();
	for (int i = 0; i < vectorSize; i++) {
		spriteList.at(i)->render();
	}
	/*
	vectorSize = panelList.size();
	for (int i = 0; i < vectorSize; i++) {
		panelList.at(i)->render();
	}

	vectorSize = fontList.size();
	for (int i = 0; i < vectorSize; i++) {
		fontList.at(i)->render();
	}

	vectorSize = lineList.size();
	for (int i = 0; i < vectorSize; i++) {
		lineList.at(i)->render();
	}*/

	d3dManager->getDevice()->EndScene();
	d3dManager->getDevice()->Present(NULL, NULL, NULL, NULL);
}

void Level::cleanup()
{
	int vectorSize;

	vectorSize = spriteList.size();
	for (int i = 0; i < vectorSize; i++) {
		spriteList.at(spriteList.size() - 1)->cleanup();
		spriteList.pop_back();
	}

	/*
	vectorSize = panelList.size();
	for (int i = 0; i < vectorSize; i++) {
		panelList.at(panelList.size() - 1)->Cleanup();
		panelList.pop_back();
	}

	vectorSize = fontList.size();
	for (int i = 0; i < vectorSize; i++) {
		fontList.at(fontList.size() - 1)->Cleanup();
		fontList.pop_back();
	}

	vectorSize = lineList.size();
	for (int i = 0; i < vectorSize; i++) {
		lineList.at(lineList.size() - 1)->Cleanup();
		lineList.pop_back();
	}*/
}

Level::~Level()
{
	cleanup();
}
