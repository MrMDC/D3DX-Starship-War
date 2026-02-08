#include "GameOver.h"
#include "Physics.h"

void GameOver::init()
{
    //Initialize the cursor sprite
    showCursor = true;
    cursor = new Sprite();
    cursor->init("Assets/Sprite/pointer.png", 1, 24, 24, 1, 1);

    //Initialize the background
    Sprite* bg = new Sprite();
    bg->init("Assets/Sprite/bg_new.png", 1, 1024, 720, 1, 1);
    spriteList.push_back(bg);

    //Initialize the back button
    backButton = new Sprite();
    backButton->init("Assets/Sprite/5.png", 1, 340, 100, 1, 1);
    backButton->setPosition(D3DXVECTOR2(320, 600));
    spriteList.push_back(backButton);

    //Initialize the text
    Font* title = new Font();
    title->init("You lost...", D3DXVECTOR2(256, 300), 512, 100, 1, D3DCOLOR_XRGB(255, 255, 255));
    fontList.push_back(title);
}

void GameOver::update()
{
    updateCursor();

    bool collide;

    //Check whether the cursor is within the back button
    collide = Physics::rectCollision(backButton->getColRect(), cursor->getColRect());
    //If the cursor collides
    if (collide) {
        backButton->setColor(D3DCOLOR_XRGB(255, 255, 255));
        if (inputManager->getMousePress(leftClick))
        {
            //Return back to main menu page
            audioManager->playAudio(click_audio);
            levelList.pop_back();
            levelList.pop_back();
        }
        else
        {
            backButton->setColor(D3DCOLOR_XRGB(200, 200, 200));
        }
    }
}

GameOver::~GameOver()
{
    //Cleanup resources
    cleanup();
}