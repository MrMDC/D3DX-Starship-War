#include "Settings.h"
#include "Physics.h"

void Settings::init() {
	//Initialize the cursor
	showCursor = true;
	cursor = new Sprite();
	cursor->init("Assets/Sprite/pointer.png", 1, 24, 24, 1, 1);

	//Initialize the background
	Sprite* bg = new Sprite();
	bg->init("Assets/Sprite/bg_new.png", 1, 1024, 720, 1, 1);
	spriteList.push_back(bg);

	//Initialize the background music size label
	Font* volumn1 = new Font();
	volumn1->init("BGM Volume", D3DXVECTOR2(200, 100), 150, 100, DT_RIGHT);
	fontList.push_back(volumn1);

	//Initialize the minus button for background music
	minusButton1 = new Sprite();
	minusButton1->init("Assets/Sprite/8.png", 1, 64, 64, 1, 1);
	minusButton1->setPosition(D3DXVECTOR2(400, 90));
	spriteList.push_back(minusButton1);

	//Adjust the background music
	Font* bgmSoundNum = new Font();
	bgmVolumn = to_string((int)(audioManager->getGrpVolume(bgm) * 100));
	bgmVolumnFinal = bgmVolumn.c_str();
	bgmSoundNum->init(bgmVolumnFinal, D3DXVECTOR2(470, 100), 150, 100, DT_CENTER);
	fontList.push_back(bgmSoundNum);

	//Initialize the add button for background music
	addButton1 = new Sprite();
	addButton1->init("Assets/Sprite/7.png", 1, 64, 64, 1, 1);
	addButton1->setPosition(D3DXVECTOR2(600, 90));
	spriteList.push_back(addButton1);

	//Initialize the sound effect size label
	Font* volumn2 = new Font();
	volumn2->init("Effect Volume", D3DXVECTOR2(200, 250), 150, 100, DT_RIGHT);
	fontList.push_back(volumn2);

	//Initialize the minus button from sound effect 
	minusButton2 = new Sprite();
	minusButton2->init("Assets/Sprite/8.png", 1, 64, 64, 1, 1);
	minusButton2->setPosition(D3DXVECTOR2(400, 240));
	spriteList.push_back(minusButton2);

	//Adjust the sound effect
	Font* effectSoundNum = new Font();
	effectVolumn = to_string((int)(audioManager->getGrpVolume(effect) * 100));
	effectVolumnFinal = effectVolumn.c_str();
	effectSoundNum->init(effectVolumnFinal, D3DXVECTOR2(470, 250), 150, 100, DT_CENTER);
	fontList.push_back(effectSoundNum);

	//Initialize the add button from sound effect
	addButton2 = new Sprite();
	addButton2->init("Assets/Sprite/7.png", 1, 64, 64, 1, 1);
	addButton2->setPosition(D3DXVECTOR2(600, 240));
	spriteList.push_back(addButton2);

	//Initialize the back button
	backButton = new Sprite();
	backButton->init("Assets/Sprite/9.png", 1, 340, 100, 1, 1);
	backButton->setPosition(D3DXVECTOR2(320, 600));
	spriteList.push_back(backButton);

}

void Settings::update()
{
	updateCursor();

	bool collide;

	collide = Physics::rectCollision(backButton->getColRect(), cursor->getColRect());
	if (collide) {
		backButton->setColor(D3DCOLOR_XRGB(255, 255, 255));
		if (inputManager->getMousePress(leftClick)) {
			audioManager->playAudio(click_audio);
			levelList.pop_back();
		}
	}
	else {
		backButton->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	collide = Physics::rectCollision(addButton1->getColRect(), cursor->getColRect());
	if (collide) {
		addButton1->setColor(D3DCOLOR_XRGB(255, 255, 255));
		if (inputManager->getMousePress(leftClick)) {
			audioManager->playAudio(click_audio);
			//Increase the background music volume
			if (audioManager->getGrpVolume(bgm) < 1) {
				audioManager->setGrpVolume(bgm, ((audioManager->getGrpVolume(bgm) * 100) + 10) / 100.0);
				bgmVolumn = to_string((int)(audioManager->getGrpVolume(bgm) * 100));
			}
		}

	}
	else {
		addButton1->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	collide = Physics::rectCollision(minusButton1->getColRect(), cursor->getColRect());
	if (collide) {
		minusButton1->setColor(D3DCOLOR_XRGB(255, 255, 255));
		if (inputManager->getMousePress(leftClick)) {
			audioManager->playAudio(click_audio);
			//Decrease the background music volume
			if (audioManager->getGrpVolume(bgm) > 0.09) {
				audioManager->setGrpVolume(bgm, ((audioManager->getGrpVolume(bgm) * 100) - 10) / 100.0);
				bgmVolumn = to_string((int)(audioManager->getGrpVolume(bgm) * 100));
			}

		}
	}
	else {
		minusButton1->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}


	collide = Physics::rectCollision(addButton2->getColRect(), cursor->getColRect());
	if (collide) {
		addButton2->setColor(D3DCOLOR_XRGB(255, 255, 255));
		if (inputManager->getMousePress(leftClick)) {
			audioManager->playAudio(click_audio);
			if (audioManager->getGrpVolume(effect) < 1) {
				//Increase the sound effect volume
				audioManager->setGrpVolume(effect, ((audioManager->getGrpVolume(effect) * 100) + 10) / 100.0);
				effectVolumn = to_string((int)(audioManager->getGrpVolume(effect) * 100));
			}
		}
	}
	else {
		addButton2->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	collide = Physics::rectCollision(minusButton2->getColRect(), cursor->getColRect());
	if (collide) {
		minusButton2->setColor(D3DCOLOR_XRGB(255, 255, 255));

		if (inputManager->getMousePress(leftClick)) {
			audioManager->playAudio(click_audio);
			if (audioManager->getGrpVolume(effect) > 0.09) {
				//Decrease the sound effect volume
				audioManager->setGrpVolume(effect, ((audioManager->getGrpVolume(effect) * 100) - 10) / 100.0);
				effectVolumn = to_string((int)(audioManager->getGrpVolume(effect) * 100));
			}
		}
	}
	else {
		minusButton2->setColor(D3DCOLOR_XRGB(200, 200, 200));
	}

	if (inputManager->getKeyPress(DIK_ESCAPE)) {
		levelList.pop_back();
	}
}

Settings::Settings()
{
	init();
}

Settings::~Settings()
{
	cleanup();
}