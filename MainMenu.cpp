#include "MainMenu.h"
#include "Physics.h"

void MainMenu::init()
{
	//Initialize the cursor
	showCursor = true;
	cursor = new Sprite();
	cursor->init("Assets/Sprite/pointer.png", 1, 24, 24, 1, 1);

	//Initialize the background
	Sprite* bg = new Sprite();
	bg->init("Assets/Sprite/bg_new.png", 1, 1024, 720, 1, 1);
	spriteList.push_back(bg);

	//Initialize the game title
	Sprite* title = new Sprite();
	title->init("Assets/Sprite/title.png", 1, 1024, 200, 1, 1);
	spriteList.push_back(title);

	//Initialize the start button
	startButton = new Sprite();
	startButton->init("Assets/Sprite/2.png", 1, 340, 100, 1, 1);
	startButton->setPosition(D3DXVECTOR2(150, 250));
	spriteList.push_back(startButton);

	//Initialize the settings button
	settingsButton = new Sprite();
	settingsButton->init("Assets/Sprite/4.png", 1, 340, 100, 1, 1);
	settingsButton->setPosition(D3DXVECTOR2(550, 250));
	spriteList.push_back(settingsButton);

	//Initialize the exit button
	exitButton = new Sprite();
	exitButton->init("Assets/Sprite/3.png", 1, 340, 100, 1, 1);
	exitButton->setPosition(D3DXVECTOR2(320, 400));
	spriteList.push_back(exitButton);

	//Initialize the control mode label
	Font* test = new Font();
	test->init("Move: WASD", D3DXVECTOR2(800, 600), 200, 225, DT_RIGHT);
	fontList.push_back(test);
	
}

void MainMenu::update()
{
	updateCursor();

	bool collide;
	//Check whether cursor collides with any of the buttons
	collide = Physics::rectCollision(startButton->getColRect(), cursor->getColRect());
	//If the cursor collides with the start button
	if (collide) {
		startButton->setColor(D3DCOLOR_XRGB(255, 255, 255));
		//If the player clicks on the left mouse button
		if (inputManager->getMousePress(leftClick)) {
			//Display the level 1 screen
			audioManager->playAudio(click_audio);
			Game* level1 = new Level1();
			level1->init();
			levelList.push_back(level1);
		}
	}
	else {
		startButton->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	collide = Physics::rectCollision(settingsButton->getColRect(), cursor->getColRect());
	//If the cursor collides with the settings button
	if (collide) {
		settingsButton->setColor(D3DCOLOR_XRGB(255, 255, 255));
		if (inputManager->getMousePress(leftClick)) {
			//Display the settings screen
			audioManager->playAudio(click_audio);
			Game* settings = new Settings();
			settings->init();
			levelList.push_back(settings);
		}
	}
	else {
		settingsButton->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	collide = Physics::rectCollision(exitButton->getColRect(), cursor->getColRect());
	//If the cursor collides with the end button
	if (collide) {
		exitButton->setColor(D3DCOLOR_XRGB(255, 255, 255));
		if (inputManager->getMousePress(leftClick)) {
			//Exit the game
			audioManager->playAudio(click_audio);
			endGame();
		}
	}
	else {
		exitButton->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	//If the player clicks on the escape button, it also exits the game
	if (inputManager->getKeyPress(DIK_ESCAPE)) {
		endGame();
	}
}

void MainMenu::endGame()
{
	//Exit the game
	PostQuitMessage(0);
}

MainMenu::MainMenu()
{
	//Initialize resources
	init();
}

MainMenu::~MainMenu()
{
	//Cleanup resources
	cleanup();
}
