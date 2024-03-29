#include "WindowManager.h"
#include "BasicHeader.h"

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

WindowManager::WindowManager()
{
	init();
}

WindowManager::~WindowManager()
{
	cleanup();
}

void WindowManager::init()
{
	//Set all members in wndClass to 0
	ZeroMemory(&wndClass, sizeof(wndClass));

	//Set window name
	LPCSTR windowName = "Bump Bump";

	//Filling wndClass
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "Bump Bump";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//Register the window
	RegisterClass(&wndClass);

	// Create the window
	handle = CreateWindowEx(0, wndClass.lpszClassName, windowName, WS_OVERLAPPEDWINDOW, 200, 100, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, GetModuleHandle(NULL), NULL);
	ShowWindow(handle, 1);

	//Hidden the window cursor
	ShowCursor(false);
}

bool WindowManager::windowIsRunning()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	if (handle == NULL) {
		return false;
	}

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		//	If quit message is received
		if (msg.message == WM_QUIT) {
			return false;
		}
		//	Translate the message 
		TranslateMessage(&msg);
		//	Dispatch message to window procedure
		DispatchMessage(&msg);
	}
	return true;
}

HWND WindowManager::getHandle()
{
	return handle;
}

void WindowManager::cleanup()
{
	UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
	if (handle != NULL) {
		handle = NULL;
	}
}
