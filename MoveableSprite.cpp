#include "MoveableSprite.h"

D3DXVECTOR2 MoveableSprite::getVelocity()
{
	return velocity;
}

int MoveableSprite::getMass()
{
	return mass;
}

D3DXVECTOR2 MoveableSprite::getForce()
{
	return force;
}

void MoveableSprite::setVelocity(D3DXVECTOR2 velocity)
{
	this->velocity = velocity;
}

void MoveableSprite::setForce(D3DXVECTOR2 force)
{
	this->force = force;
}

void MoveableSprite::setMoveSpeed(int moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void MoveableSprite::initMove(int mass, int moveSpeed, float rotationSpeed)
{
	//Initialize the moveable sprite variables
	this->mass = mass;
	this->moveSpeed = moveSpeed;
	this->rotationSpeed = rotationSpeed;
}

void MoveableSprite::updateMove()
{
}

void MoveableSprite::adjustVelocity()
{
	//Calculate the velocity of the sprite
	acceleration = force / mass;
	velocity += acceleration;
}

void MoveableSprite::move()
{
	//Calculate the movement of the sprite
	velocity *= (1 - friction);
	position += velocity;
}
