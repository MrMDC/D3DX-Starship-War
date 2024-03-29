#include "Main.h"

void initLevel() {
	Level* mainMenu = new MainMenu();
	mainMenu->init();
	levelList.push_back(mainMenu);
}

void init() {

	windowManager = new WindowManager();
	d3dManager = new D3DManager();
	if (FAILED(hr)) return;
	inputManager = new InputManager();
	frameTimer = new FrameTimer(30);
	audioManager = new AudioManager();
	audioManager->startBgm();
	initLevel();
}

void cleanup() {
	int vectorSize;

	vectorSize = levelList.size();
	for (int i = 0; i < vectorSize; i++) {
		levelList.at(levelList.size() - 1)->cleanup();
		levelList.pop_back();
	}
	
	audioManager->cleanup();
	inputManager->cleanup();
	d3dManager->cleanup();
	windowManager->cleanup();
}

int getFramesToUpdate() {
	return frameTimer->framesToUpdate();
}

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	init();
	if (FAILED(hr)) return 0;

	while (windowManager->windowIsRunning()) {
		levelList.back()->input();
		for (int i = 0; i < getFramesToUpdate(); i++)
			levelList.back()->update();
		levelList.back()->render();
		audioManager->update();
	}

	cleanup();

	return 0;

}