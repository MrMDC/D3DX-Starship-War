#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include "MoveableSprite.h"

class Physics
{
public:
	static bool rectCollision(RECT rectA, RECT rectB);
	static bool circleCollision(MoveableSprite* objA, MoveableSprite* objB);
	static void circleCollisionMovement(MoveableSprite* objA, MoveableSprite* objB);
};

#endif