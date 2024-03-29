#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define KEYDOWN(name, key) (name[key] & 0x80)
#define BUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

#include "BasicHeader.h"

enum MouseClick {
	leftClick, rightClick
};

class InputManager
{
protected:
	LPDIRECTINPUT8 dInput;						// DirectInput object
	LPDIRECTINPUTDEVICE8 dInputKeyboardDevice;  // Keyboard device
	LPDIRECTINPUTDEVICE8 dInputMouseDevice;     // Mouse device
	DIMOUSESTATE mouseState;					// Mouse state

	// Keyboard
	BYTE diKeys[256];                 // Snapshot of the keyboard
	bool keyPressed[256];             // Array to track key presses
	int keyCodeDIK[256];              // Array to map key codes to DIK values

	// Mouse
	LONG xPos;							// Current X position of the mouse cursor
	LONG yPos;							// Current Y position of the mouse cursor
	bool leftMouseClick;				// Flag for left mouse button click
	bool rightMouseClick;				// Flag for right mouse button click

public:
	void init();

	// Member functions for DInputManager
	void readInput();                    // Method to handle input

	bool getKeyPress(int key);   // Method to check if a key is pressed

	bool getMousePress(int mouseClick);  // Method to check if a mouse button is pressed
	D3DXVECTOR2 getMousePosition();      // Method to get the mouse position
	void resetMousePosition();           // Method to reset the mouse position

	void cleanup();

	InputManager();
	~InputManager();
};

#endif