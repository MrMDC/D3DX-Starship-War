#pragma once
#ifndef MOVEABLE_SPRITE
#define MOVEABLE_SPRITE

#include "Sprite.h"

class MoveableSprite : public Sprite
{
protected:
	int mass;
	int moveSpeed;
	float rotationSpeed;
	D3DXVECTOR2 velocity;
	D3DXVECTOR2 acceleration = D3DXVECTOR2(0, 0);
	D3DXVECTOR2 force;

public:
	D3DXVECTOR2 getVelocity();
	int getMass();
	D3DXVECTOR2 getForce();

	void setVelocity(D3DXVECTOR2 velocity);
	void setForce(D3DXVECTOR2 force);
	void setMoveSpeed(int moveSpeed);

	void initMove(int mass, int moveSpeed, float rotationSpeed);
	virtual void updateMove();
	void adjustVelocity();
	void move();
};

#endif