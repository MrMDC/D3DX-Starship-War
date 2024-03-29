#pragma once
#ifndef MOREHEADER_H
#define MOREHEADER_H

#include "BasicHeader.h"
#include "Game.h"
#include "D3DManager.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "FrameTimer.h"

extern vector<Game*> levelList;

extern D3DManager* d3dManager;
extern InputManager* inputManager;
extern AudioManager* audioManager;
extern FrameTimer* frameTimer;

extern float friction;

#endif