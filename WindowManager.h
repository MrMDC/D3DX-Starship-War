#pragma once
#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <iostream>
#include <Windows.h>

class WindowManager
{
protected:
	WNDCLASS wndClass;
	HWND handle;

public:
	void init();
	bool windowIsRunning();
	HWND getHandle();
	void cleanup();

	WindowManager();
	~WindowManager();
};

#endif