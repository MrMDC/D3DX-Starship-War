#include "Rock.h"
#include "Helper.h"

int Rock::count = 0;

bool Rock::getRockBreak()
{
	return rockBreak;
}

bool Rock::getAnimateDone()
{
	return animateDone;
}

void Rock::setRockBreak(bool rockBreak)
{
	this->rockBreak = rockBreak;
}

void Rock::setAnimateDone(bool animateDone)
{
	this->animateDone = animateDone;
}

void Rock::init()
{
	//Set the rock's texture
	setTexture("Assets/Sprite/rock.png");
	setTextureData(1, 64, 64, 1, 1);
	//Randomize the rock's position
	setDefaultRotation(0.0f);
	setPosition(randomPosition(count));
	initMove(randomMass(), 0, 0.2f);
	//Randomize the rock's scale
	float scaling = Helper::remapRange(mass, 10, 40, 0.7, 1.1);
	setScaling(D3DXVECTOR2(scaling, scaling));
	//Set the physics aspects of the rock
	setForce(randomForce());
	setVelocity(force * 3);
	radius *= 0.95;
	//Generate the rocks
	count++;
}

void Rock::update()
{
	//Update the rock sprite and the rock's position if the rock is not broken
	if (!rockBreak) {
		updateFrameRect();
		move();
	}
	//Update the rock explosion animation
	else {
		updateFrameLoop();
		updateFrameRect();
	}
}

void Rock::updateFrameLoop()
{
	//If there is still frames available after the current frame
	if (currentFrame < maxFrame) {
		currentFrame++;
	}
	else {
		animateDone = true;
	}
}

void Rock::move()
{
	//Velocity of the rock
	velocity *= (1 - (friction / 1.2));
	//Determine how the rock rotates and moves
	float rotationCount = Helper::remapRange(D3DXVec2LengthSq(&velocity), 200, 0, 0.2, 0);
	rotationCount *= (velocity.x) ? 1 : -1;
	//Move the rock according to the velocity
	rotation += rotationCount;
	position += velocity;
}

void Rock::animateInit()
{
	//Set the rock explosion sprite
	setTexture("Assets/Sprite/anim.png");
	setTextureData(9, 256, 256, 3, 3);
	currentFrame = 0;
	//The rock has exploded
	rockBreak = true;
}

D3DXVECTOR2 Rock::randomPosition(int index)
{
	// Generate random coordinates within the defined range
	int x = rand() % (WINDOW_WIDTH + 1);
	int y = rand() % (WINDOW_HEIGHT + 1);

	return D3DXVECTOR2(x, y);
}

D3DXVECTOR2 Rock::randomForce()
{
	int maxForce = 2;
	int minForce = -2;

	int randomForce_X = 0;
	int randomForce_Y = 0;

	//Generate random forces within the defined range
	while (randomForce_X == 0 && randomForce_Y == 0) {
		randomForce_X = rand() % (maxForce - minForce + 1) + minForce;
		randomForce_Y = rand() % (maxForce - minForce + 1) + minForce;
	}

	return D3DXVECTOR2(randomForce_X, randomForce_Y);
}

int Rock::randomMass()
{
	int maxMass = 40;
	int minMass = 10;

	//Generate random mass within the defined range
	return rand() % (maxMass - minMass + 1) + minMass;
}

Rock::Rock()
{
	//Initialize the rock in its unexploded form
	rockBreak = false;
	animateDone = false;
}
