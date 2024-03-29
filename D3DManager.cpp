#include "D3DManager.h"

void D3DManager::init()
{
	//Define Direct3D 9
	IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(d3dPP));

	//Set Direct3D9 member
	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = WINDOW_WIDTH;   //Background Width
	d3dPP.BackBufferHeight = WINDOW_HEIGHT; //Background Height
	d3dPP.hDeviceWindow = windowManager->getHandle(); // Window handle

	//	Create a Direct3D 9 device
	hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, windowManager->getHandle(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);
	if (FAILED(hr)) return;

	//Create Sprite Brush 
	hr = D3DXCreateSprite(d3dDevice, &spriteBrush);
	if (FAILED(hr)) return;

	//Create Font Brush
	hr = D3DXCreateFont(d3dDevice, 25, 0, FW_BOLD, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Albertus", &fontBrush);
	if (FAILED(hr)) return;

	//Create Line Brush
	hr = D3DXCreateLine(d3dDevice, &lineBrush);
	if (FAILED(hr)) return;
}

D3DManager::D3DManager()
{
	init();
}

D3DManager::~D3DManager()
{
	cleanup();
}

IDirect3DDevice9* D3DManager::getDevice()
{
	return d3dDevice;
}

LPD3DXSPRITE D3DManager::getSpriteBrush()
{
	return spriteBrush;
}

LPD3DXFONT D3DManager::getFontBrush()
{
	return fontBrush;
}

LPD3DXLINE D3DManager::getLineBrush()
{
	return lineBrush;
}

void D3DManager::cleanup()
{
	// Release the brush and device when exiting.
	// Reset pointers to NULL

	if (spriteBrush != NULL) {
		spriteBrush->Release();
		spriteBrush = NULL;
	}

	if (fontBrush != NULL) {
		fontBrush->Release();
		fontBrush = NULL;
	}

	if (lineBrush != NULL) {
		lineBrush->Release();
		lineBrush = NULL;
	}

	if (d3dDevice != NULL)
	{
		d3dDevice->Release();
		d3dDevice = NULL;
	}
}
