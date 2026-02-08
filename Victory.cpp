#include "Victory.h"
#include "Physics.h"

void Victory::init()
{
    showCursor = true;
    cursor = new Sprite();
    cursor->init("Assets/Sprite/pointer.png", 1, 24, 24, 1, 1);

    Sprite* bg = new Sprite();
    bg->init("Assets/Sprite/bg_new.png", 1, 1024, 720, 1, 1);
    spriteList.push_back(bg);

    backButton = new Sprite();
    backButton->init("Assets/Sprite/5.png", 1, 340, 100, 1, 1);
    backButton->setPosition(D3DXVECTOR2(320, 600));
    spriteList.push_back(backButton);

    Font* title = new Font();
    title->init("You won!", D3DXVECTOR2(256, 300), 512, 100, 1, D3DCOLOR_XRGB(255, 255, 255));
    fontList.push_back(title);

    Line* star = new Line();
    star->createStar(D3DXVECTOR2(512, 300), 450);
    lineList.push_back(star);
    
}

void Victory::update()
{
    updateCursor();

    bool collide;
    collide = Physics::rectCollision(backButton->getColRect(), cursor->getColRect());
    if (collide) {
        backButton->setColor(D3DCOLOR_XRGB(255, 255, 255));
        if (inputManager->getMousePress(leftClick))
        {
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

Victory::~Victory()
{
    cleanup();
}
