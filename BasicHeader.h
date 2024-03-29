#pragma once
#ifndef BASICHEADER_H
#define BASICHEADER_H

// Define minimal windows headers
#define WIN32_LEAN_AND_MEAN

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 720

// Include necessary C++ standard libraries and Windows headers
#include <iostream>
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <math.h>
#include <vector>
#include <string>

#include "WindowManager.h"

// link with external libraries
// **only works on Windows**
#pragma comment (lib, "d3d9.lib") 
#pragma comment (lib, "d3dx9.lib") 
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "fmod_vc.lib")

// standard namespace
using namespace std;

extern HRESULT hr;

extern WindowManager* windowManager;

#endif