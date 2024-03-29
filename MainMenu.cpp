#include "MainMenu.h"

void MainMenu::init()
{
	Sprite* bg = new Sprite();
	bg->init("bg_new.png", 1, 1024, 720, 1, 1);
	spriteList.push_back(bg);
	Sprite*  title = new Sprite();
	title->init("Assets/Sprite/title.png", 1, 1024, 400, 1, 1);
	spriteList.push_back(title);

}

void MainMenu::update()
{
	
	if (inputManager->getKeyPress(DIK_ESCAPE)) {
		endGame();
	}
	
}

void MainMenu::endGame()
{
	PostQuitMessage(0);
}

MainMenu::MainMenu()
{
	init();

}

MainMenu::~MainMenu()
{
	cleanup();
}
