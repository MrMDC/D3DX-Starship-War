#include "Physics.h"
#include "Physics.h"

bool Physics::rectCollision(RECT rectA, RECT rectB)
{
	//Check whether two rectangle sprites collide
	if (rectA.bottom < rectB.top) return false;
	if (rectA.top > rectB.bottom) return false;
	if (rectA.right < rectB.left) return false;
	if (rectA.left > rectB.right) return false;
	return true;
}

bool Physics::circleCollision(MoveableSprite* objA, MoveableSprite* objB)
{
	//Check whether two circle sprites collide
	D3DXVECTOR2 distance = objA->getPosition() - objB->getPosition();
	if ((pow(objA->getRadius() + objB->getRadius(), 2)) >= D3DXVec2LengthSq(&distance)) {
		return true;
	}
	return false;
}

void Physics::circleCollisionMovement(MoveableSprite* objA, MoveableSprite* objB)
{
	//Get the colliding distance between two moveable sprites
	D3DXVECTOR2 distance = objB->getPosition() - objA->getPosition();
	float distanceMagnitude = D3DXVec2Length(&distance);

	// Calculate the collision normal (unit vector)
	D3DXVECTOR2 collisionNormal = distance / distanceMagnitude;

	// Separate the circles to avoid overlap (assuming they are solid)
	float overlap = objA->getRadius() + objB->getRadius() - distanceMagnitude;
	objA->setPosition(objA->getPosition() - overlap * 0.5f * collisionNormal);
	objB->setPosition(objB->getPosition() + overlap * 0.5f * collisionNormal);

	// Calculate relative velocity
	D3DXVECTOR2 relativeVelocity = objA->getVelocity() - objB->getVelocity();
	float relativeSpeed = D3DXVec2Dot(&relativeVelocity, &collisionNormal);

	// Calculate impulse using perfectly elastic collision formula
	float impulse = (-2.0f * relativeSpeed) / (1.0f / objA->getMass() + 1.0f / objB->getMass());

	// Update velocities of both circles
	objA->setVelocity(objA->getVelocity() + impulse * collisionNormal / objA->getMass());
	objB->setVelocity(objB->getVelocity() - impulse * collisionNormal / objB->getMass());
}
