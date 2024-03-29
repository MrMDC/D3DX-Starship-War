#pragma once
#ifndef MAIN_H
#define MAIN_H

#include "MoreHeader.h"
#include "MainMenu.h"

vector<Game*> levelList;

HRESULT hr;

float friction = .03f;

WindowManager* windowManager;
D3DManager* d3dManager;
InputManager* inputManager;
AudioManager* audioManager;
FrameTimer* frameTimer;


#endif