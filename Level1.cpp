#include "Level1.h"
#include "Physics.h"

void Level1::init()
{
	showCursor = false;

	//Initialize the background
	Sprite* bg = new Sprite();
	bg->init("Assets/Sprite/bg_new.png", 1, 1024, 720, 1, 1);
	spriteList.push_back(bg);

	//Initialize the player's spaceship
	player = new Player();
	player->init();
	spriteList.push_back(player);

	//Initialize all the rock objects
	for (int i = 0; i < 20; i++) {
		Rock* newRock = new Rock();
		newRock->init();
		rockList.push_back(newRock);
		spriteList.push_back(newRock);
	}

	//Display the time left label
	timerText = new Font();
	timerTextString = "Time Left: " + to_string(timer);
	timerTextLString = timerTextString.c_str();
	timerText->init(timerTextLString, D3DXVECTOR2(10, 10), 200, 100, DT_LEFT);
	fontList.push_back(timerText);

	//Display the rock left label
	rockRemain = new Font();
	rockRemainString = "Rock Left: " + to_string(rockList.size());
	rockRemainLString = rockRemainString.c_str();
	rockRemain->init(rockRemainLString, D3DXVECTOR2(10, 50), 200, 100, DT_LEFT);
	fontList.push_back(rockRemain);

	//Set the default data
	counter = 0;
	timer = 100;
}

void Level1::update()
{
	//If all the rocks are broken
	if (rockList.size() == 0) {
		//Display the victory screen
		audioManager->playAudio(win);
		Game* victory = new Victory();
		victory->init();
		levelList.push_back(victory);
	}
	
	counter++;

	//Reduce the time left by 1 second if all frames within a second exceeds
	if (counter > frameTimer->getFPS()) {
		counter -= frameTimer->getFPS();
		timer--;
	}

	//If the is no time remaining
	if (timer < 0) {
		//Displayt the game over screen
		audioManager->playAudio(game_over);
		Game* gameOver = new GameOver();
		gameOver->init();
		levelList.push_back(gameOver);
	}

	for (int i = 0; i < spriteList.size(); i++) {


		// Handle rock collisions with other rocks
		if (Rock* rock = dynamic_cast<Rock*>(spriteList.at(i))) {
			//count the velocity
			rock->adjustVelocity();

			// Check for collisions with other rocks
			for (int j = 0; j < rockList.size() && rock != rockList.at(j); j++) {
				if (Physics::circleCollision(rock, rockList.at(j))) {
					Physics::circleCollisionMovement(rock, rockList.at(j));
				}
			}

			// Remove rocks that have finished their animation
			if (rock->getAnimateDone()) {
				spriteList.erase(remove(spriteList.begin(), spriteList.end(), rock), spriteList.end());
				rockList.erase(remove(rockList.begin(), rockList.end(), rock), rockList.end());
				updateText();
				continue;
			}
		}

		// Handle player and screen boundary collisions
		if (MoveableSprite* moveObj = dynamic_cast<MoveableSprite*>(spriteList.at(i))) {
			if (moveObj->getPosition().x < -1) {
				moveObj->setPosition(D3DXVECTOR2(WINDOW_WIDTH - moveObj->getSpriteWidth() - 1, moveObj->getPosition().y));
			}

			if (moveObj->getPosition().x >= WINDOW_WIDTH - moveObj->getSpriteWidth()) {
				moveObj->setPosition(D3DXVECTOR2(0, moveObj->getPosition().y));
			}

			if (moveObj->getPosition().y < -1) {
				moveObj->setPosition(D3DXVECTOR2(moveObj->getPosition().x, WINDOW_HEIGHT - moveObj->getSpriteHeight() - 1));
			}

			if (moveObj->getPosition().y >= WINDOW_HEIGHT - moveObj->getSpriteHeight()) {
				moveObj->setPosition(D3DXVECTOR2(moveObj->getPosition().x, 0));
			}
		}

		// Handle player and rock collisions
		if (spriteList.at(i) == player) {

			player->updateMove();

			// Check for collisions with rocks
			for (int j = 0; j < rockList.size(); j++) {
				if (!rockList.at(j)->getRockBreak()) {
					if (Physics::circleCollision(player, rockList.at(j))) {
						Physics::circleCollisionMovement(player, rockList.at(j));
						// Play collision sound
						audioManager->playAudio(explosion);
						rockList.at(j)->animateInit();
					}
				}
			}
			// Update player's frame and movement
			player->updateFrame();
			player->move();
			continue;
		}

		// Update other game objectss
		spriteList.at(i)->update();
	}

	updateText();

	if (inputManager->getKeyPress(DIK_Q)) {
		levelList.pop_back();
	}
}

void Level1::updateText()
{
	//Update the text accordingly for any updated values
	timerTextString = "Time Left: " + to_string(timer);
	rockRemainString = "Rock Left: " + to_string(rockList.size());
}
