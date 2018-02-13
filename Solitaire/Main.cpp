#include <windows.h>
#include <windowsx.h>
#include <time.h>

#include "resource.h"

#define WINDOW_CLASS_NAME L"BSENGGFRAMEWORK"

LRESULT CALLBACK
WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	HMENU Menu = (HMENU)IDR_MENU1;

	switch (_uiMsg)
	{
		case WM_PAINT:
		{

		}
		break;

		case WM_LBUTTONUP:
		{

		}
		break;

		case WM_LBUTTONDOWN:
		{

		}
		break;

		case WM_MOUSEMOVE:
		{

		}
		break;

		case WM_COMMAND:
		{
			switch (LOWORD(_wParam))
			{
				case ID_FILE_NEWGAME:
				{

					break;
				}

				case ID_FILE_QUIT:
				{

					break;
				}
				default: break;
			}
			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return(0);
		}
		default: break;
	}
	return (DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam));
}

HWND
CreateAndRegisterWindow(HINSTANCE _hInstance, int _iWidth, int _iHeight, LPCWSTR _pcTitle)
{
	WNDCLASSEX winclass;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winclass))
	{
		return(0);
	}

	HWND hwnd;
	hwnd = CreateWindowEx(NULL,
		WINDOW_CLASS_NAME,
		_pcTitle,
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		_iWidth, _iHeight,
		NULL, NULL,
		_hInstance, NULL);

	if (!hwnd)
	{
		return (0);
	}
	return (hwnd);
}

int WINAPI
WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _iCmdShow)
{
	MSG msg;

	ZeroMemory(&msg, sizeof(MSG));

	srand(static_cast<unsigned int>(time(NULL)));

	const int kiWidth = 900;
	const int kiHeight = 600;

	HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"Solitaire");



	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

		}
	}



	return (static_cast<int>(msg.wParam));
}