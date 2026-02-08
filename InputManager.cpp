#include "InputManager.h"
#include "MoreHeader.h"

InputManager::InputManager()
{
	init();
}

InputManager::~InputManager()
{
	cleanup();
}

void InputManager::init()
{
	// Create the Direct Input object.
	hr = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
	if (FAILED(hr)) return;

	// Create the keyboard device.
	hr = dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
	if (FAILED(hr)) return;

	// Create the mouse device.
	hr = dInput->CreateDevice(GUID_SysMouse, &dInputMouseDevice, NULL);
	if (FAILED(hr)) return;

	// Set the input data format.
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputMouseDevice->SetDataFormat(&c_dfDIMouse);

	// Set the cooperative level.
	dInputKeyboardDevice->SetCooperativeLevel(windowManager->getHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	dInputMouseDevice->SetCooperativeLevel(windowManager->getHandle(), DISCL_FOREGROUND | DISCL_EXCLUSIVE);

	// Set default keybinds
	for (int i = 0; i < 256; i++)
		keyCodeDIK[i] = i;

	xPos = 512;
	yPos = 300;
}

void InputManager::readInput()
{
	// Acquire the device.
	dInputKeyboardDevice->Acquire();
	dInputMouseDevice->Acquire();

	// Keyboard
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	for (int i = 0; i < 256; i++)
		keyPressed[i] = (KEYDOWN(diKeys, i));

	// Mouse
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);

	xPos += mouseState.lX;
	yPos += mouseState.lY;

	leftMouseClick = BUTTONDOWN(mouseState, leftClick);
	rightMouseClick = BUTTONDOWN(mouseState, rightClick);
}

bool InputManager::getKeyPress(int key)
{
	return keyPressed[keyCodeDIK[key]];
}

bool InputManager::getMousePress(int mouseClick)
{
	//Determine which mouse button was clicked
	if (mouseClick == leftClick) {
		return leftMouseClick;
	}
	else if (mouseClick == rightClick) {
		return rightMouseClick;
	}
	return false;
}

D3DXVECTOR2 InputManager::getMousePosition()
{
	return D3DXVECTOR2(xPos, yPos);
}

void InputManager::resetMousePosition()
{
	//Reset the mouse position to this position
	xPos = 512;
	yPos = 300;

	SetCursorPos(612, 300);
}

void InputManager::cleanup()
{
	//Cleanup the keyboard
	if (dInputKeyboardDevice != NULL) {
		dInputKeyboardDevice->Unacquire();
		dInputKeyboardDevice->Release();
		dInputKeyboardDevice = NULL;
	}

	//Cleanup the mouse
	if (dInputMouseDevice != NULL) {
		dInputMouseDevice->Unacquire();
		dInputMouseDevice->Release();
		dInputMouseDevice = NULL;
	}

	//Cleanup the DirectX input
	if (dInput != NULL) {
		dInput->Release();
		dInput = NULL;
	}
}
