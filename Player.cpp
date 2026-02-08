#include "Player.h"

void Player::init()
{
	//Initialize the player data
	setTexture("Assets/Sprite/spaceship.png");
	setTextureData(2, 64, 64, 2, 2);
	setPosition(D3DXVECTOR2(500, 600));
	initMove(10, 4, 0.1f);

	//Initialize the player's stats
	hp = 3;
	moveSpeed = 4;
}

void Player::updateFrame()
{
	updateFrameLoop();

	//Update the sprite dimension for the player
	spriteRect.left = 0;
	spriteRect.top = currentFrame % maxFrame % spriteRow * spriteHeight;
	spriteRect.right = spriteRect.left + spriteWidth;
	spriteRect.bottom = spriteRect.top + spriteHeight;

	//Update the collision rectangle for the player
	colRect.top = position.y;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;
	colRect.bottom = colRect.top + spriteHeight;
}

void Player::updateMove()
{
	//Initialize the move force of the player
	force.x = 0;
	force.y = 0;

	//Accelerate the player according to the direction they currently facing
	if (inputManager->getKeyPress(DIK_W)) {
		force.x = sin(rotation) * moveSpeed;
		force.y = -cos(rotation) * moveSpeed;
	}

	if (inputManager->getKeyPress(DIK_S)) {
		force.x = sin(rotation) * -moveSpeed;
		force.y = -cos(rotation) * -moveSpeed;
	}

	//Rotate the player
	if (inputManager->getKeyPress(DIK_A)) {
		rotation -= rotationSpeed;
	}

	if (inputManager->getKeyPress(DIK_D)) {
		rotation += rotationSpeed;
	}

	//Update the player's velocity
	adjustVelocity();
}

int Player::getHp()
{
	return hp;
}

void Player::damage()
{
	//Deduct hitpoint
	hp--;
}

bool Player::getIsDead()
{
	//Check if the hitpoint is below or equal to 0, indicating the plyaer is dead
	return hp <= 0;
}
