// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw.h"

#define MAX_LOADSTRING 100
#define TMR_1 1
#define TMR_2 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;
int leftright = 200;
int updown = 100;

int h[6];
int g[6];

int xa=200, xb=260, xc=320, xd=380, xe=440, xf=500;
int ya=550, yb=550, yc=550, yd=550, ye=550, yf=550;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

struct Figure {
	int x;
	int y;
	int ksztalt;
};

Figure tab[6] = { { xa,ya, 1}, {xb, yb, 1}, {xc, yc, 1}, {xd, yd, 1}, {xe, ye, 2}, {xf, yf, 3 } };

void Drawell(HDC hdc, int x, int y) {
	HPEN hPenOld;
	HPEN hEllipsePen;
	COLORREF qEllipseColor;
	qEllipseColor = RGB(100, 100, 0);
	hEllipsePen = CreatePen(PS_SOLID, 0, qEllipseColor);
	hPenOld = (HPEN)SelectObject(hdc, hEllipsePen);

	Arc(hdc, x, y, x+50, y+50, 0, 0, 0, 0);
	SelectObject(hdc, hPenOld);
}

void Drawline(HDC hdc, int lr, int ud) {
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawLine(&pen, lr, 100, lr, ud);

}

void DrawRect(HDC hdc,int x,int y) {
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawRectangle(&pen, x, y, 50, 50);
}

void Drawwaga(HDC hdc, int x, int y) {
	Graphics graphics(hdc);
	Pen pen(Color(55, 32, 124, 23));
	graphics.DrawRectangle(&pen, x, y, 100, 50);
	graphics.DrawLine(&pen, x, y, x + 100, y + 50);
}

void DrawCrane(HDC hdc) {
	Graphics graphics(hdc);
	Pen pen(Color(205, 133, 111, 155));
	graphics.DrawLine(&pen, 100, 100, 100, 600);
	graphics.DrawLine(&pen, 140, 100, 140, 600);
	graphics.DrawLine(&pen, 10, 100, 100, 100);
	graphics.DrawLine(&pen, 140, 100, 730, 100);
	graphics.DrawLine(&pen, 10, 70, 100, 70);
	graphics.DrawLine(&pen, 140, 70, 700, 70);
	graphics.DrawLine(&pen, 100, 70, 100, 40);
	graphics.DrawLine(&pen, 140, 70, 140, 40);
	graphics.DrawLine(&pen, 140, 70, 140, 40);
	graphics.DrawLine(&pen, 100, 40, 140, 40);
	graphics.DrawLine(&pen, 10, 70, 10, 100);
	graphics.DrawLine(&pen, 60, 600, 800, 600);
	graphics.DrawLine(&pen, 700, 70, 730, 100);
	for (int i = 3; i--; i < 0)
	{
		graphics.DrawLine(&pen, 70 - 30 * i, 70, 100 - 30 * i, 100);
		graphics.DrawLine(&pen, 70 - 30 * i, 70, 70 - 30 * i, 100);
	}
	for (int i = 19; i--; i < 0)
	{
		graphics.DrawLine(&pen, 680 - 30 * i, 70, 710 - 30 * i, 100);
		graphics.DrawLine(&pen, 680 - 30 * i, 70, 680 - 30 * i, 100);
	}
	for (int i = 20; i--; i < 0)
	{
		graphics.DrawLine(&pen, 100, 600 - 28 * i, 140, 572 - 28 * i);
		graphics.DrawLine(&pen, 100, 600 - 28 * i, 140, 600 - 28 * i);
	}


}
void Drawtriangle(HDC hdc, int x, int y) {
	Graphics graphics(hdc);
	Pen pen(Color(205, 133, 111, 155));
	graphics.DrawLine(&pen, x, 600, x+50, 600);
	graphics.DrawLine(&pen, x, 600, x+25, y);
	graphics.DrawLine(&pen, x+50, 600, x+25, y);
}

void Drawodbijacz(HDC hdc) {
	Graphics graphics(hdc);
	Pen pen(Color(205, 133, 111, 155));
	graphics.DrawRectangle(&pen, 750, 400, 50, 250);
}

int OnCreate(HWND window)
{
   SetTimer(window, TMR_1, 250, 0);
   return 0;
 

}



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	
	
	// 1 - ellipse; 2 - triangle; 3 - rectengle;
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	value= 10;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	GdiplusShutdown(gdiplusToken);

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   
   OnCreate(hWnd);
   

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;

	HDC hdc;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
			//case GetAsyncKeyState('P'):
				//if (leftright < 730) leftright++;
				//break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		DrawCrane(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint
			InvalidateRect(hWnd, NULL, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			DrawCrane(hdc);
			Drawell(hdc, xa, ya);
			Drawell(hdc, xb, yb);
			Drawell(hdc, xc, yc);
			Drawell(hdc, xd, yd);
			DrawRect(hdc, xe, ye);
			Drawtriangle(hdc, xf, yf);
			Drawwaga(hdc, 650, 550);
			Drawline(hdc, leftright, updown);
			int ile = 6;
			if (xa < 625) { ile--; }
			if (xb < 625) { ile--; }
			if (xc < 625) { ile--; }
			if (xd < 625) { ile--; }
			if (xe < 625) { ile--; }
			if (xf < 625) { ile--; }
			Drawwaga(hdc, 250+100*ile, 600);
			Drawodbijacz(hdc);
			

			while (1)

			{
				if (GetAsyncKeyState('D'))
				{
					if (leftright < 730) leftright = leftright + 10;
					break;
				}

				if (GetAsyncKeyState('A'))
				{
					if (leftright > 200) leftright = leftright - 10;
					break;
				}

				if (GetAsyncKeyState('W'))
				{
					if (updown > 110) updown = updown - 10;
					break;
				}

				if (GetAsyncKeyState('S'))
				{
					if (updown < 580) updown = updown + 10;
					break;
				}
				if (GetAsyncKeyState('V')) {

					if (updown > (ya - 21) && updown < (ya + 21) && leftright > xa && leftright < xa + 50 && tab[0].ksztalt == 1) {
						ya = updown;
						xa = leftright - 25;
						h[0] = updown;
						break;
					}
					else if (updown > (yb - 21) && updown < (yb + 21) && leftright > xb && leftright < xb + 50 && tab[1].ksztalt == 1) {
						yb = updown;
						xb = leftright - 25;
						h[1] = updown;
						break;
					}
					else if (updown > (yc - 21) && updown < (yc + 21) && leftright > xc && leftright < xc + 50 && tab[2].ksztalt == 1) {
						yc = updown;
						xc = leftright - 25;
						h[2] = updown;
						break;
					}
					else if (updown > (yd - 21) && updown < (yd + 21) && leftright > xd && leftright < xd + 50 && tab[3].ksztalt == 1) {
						yd = updown;
						xd = leftright - 25;
						h[3] = updown;
						break;
					}
					else if (updown > (ye - 21) && updown < (ye + 21) && leftright > xe && leftright < xe + 50 && tab[4].ksztalt == 1) {
						ye = updown;
						xe = leftright - 25;
						h[4] = updown;
						break;
					}
					else if (updown > (yf - 21) && updown < (yf + 21) && leftright > xf && leftright < xf + 50 && tab[5].ksztalt == 1) {
						yf = updown;
						xf = leftright - 25;
						h[5] = updown;
						break;
					}

					else { break; }

				}

				if (ya < 550 && xa < 605) {
					g[0]++;
					ya = h[0] + g[0] * g[0];
					break;
				}
				if (ya < 545) {
					g[0] = 0;
				}
				if (yb < 550 && xb < 605) {
					g[1]++;
					yb = h[1] + g[1] * g[1];
					break;
				}
				if (yb < 545) {
					g[1] = 0;
				}
				if (yc < 550 && xc < 605) {
					g[2]++;
					yc = h[2] + g[2] * g[2];
					break;
				}
				if (yc < 545) {
					g[2] = 0;
				}
				if (yd < 550 && xd < 605) {
					g[3]++;
					yd = h[3] + g[3] * g[3];
					break;
				}

				if (yd < 545) {
					g[3] = 0;
				}
				if (ye < 550 && xe < 605) {
					g[4]++;
					ye = h[4] + g[4] * g[4];
					break;
				}
				if (ye < 545) {
					g[4] = 0;
				}
				if (yf < 550 && xf < 605) {
					g[5]++;
					yf = h[5] + g[5] * g[5];
					break;
				}
				if (yf < 545) {
					g[5] = 0;
				}

				if(ile<=3){


				if (ya < (500 - 50 * ile) && xa >= 605) {
					g[0]++;
					ya = h[0] + g[0] * g[0];
					break;
				}
				if (ya < (430 - 50 * ile) && xa >= 605) {
					g[0] = 0;
				}
				if (yb < (500 - 50 * ile) && xb >= 605) {
					g[1]++;
					yb = h[1] + g[1] * g[1];
					break;
				}
				if (yb < (430 - 50 * ile) && xb >= 605) {
					g[1] = 0;
				}
				if (yc < (500 - 50 * ile) && xc >= 605) {
					g[2]++;
					yc = h[2] + g[2] * g[2];
					break;
				}
				if (yc < (430 - 50 * ile) && xc >= 605) {
					g[2] = 0;
				}
				if (yd < (500 - 50 * ile) && xd >= 605) {
					g[3]++;
					yd = h[3] + g[3] * g[3];
					break;
				}

				if (yd < (430 - 50 * ile) && xd >= 605) {
					g[3] = 0;
				}
				if (ye < (500 - 50 * ile) && xe >= 605) {
					g[4]++;
					ye = h[4] + g[4] * g[4];
					break;
				}
				if (ye < (430 - 50 * ile) && xe >= 605) {
					g[4] = 0;
				}
				if (yf < (500 - 50 * ile) && xf >= 605) {
					g[5]++;
					yf = h[5] + g[5] * g[5];
					break;
				}
				if (yf < (430 - 50 * ile) && xf >= 605) {
					g[5] = 0;
				}

			}

				if (ile > 3) {
					if (xa >= 605) {
						xa = xa - 50;
						break;
					}
					else if (xb >= 605) {
						xb = xb - 50;
						break;
					}
					else if (xc >= 605) {
						xc = xc - 50;
						break;
					}
					else if (xd >= 605) {
						xd = xd - 50;
						break;
					}
					else if (xe >= 605) {
						xe = xe - 50;
						break;
					}
					else if (xf >= 605) {
						xf = xf - 50;
						break;
					}
						break;
					}

		
		if(ile>3){


				if (ya < (500 - 50 * ile) && xa >= 605) {
					g[0]++;
					ya = h[0] + g[0] * g[0];
					xa = xa - 50;
					break;
				}
				if (ya < (480 - 50 * ile) && xa >= 605) {
					g[0] = 0;
				}
				if (yb < (550 - 50 * ile) && xb >= 605) {
					g[1]++;
					yb = h[1] + g[1] * g[1];
					xb = xb - 50;
					break;
				}
				if (yb < (480 - 50 * ile) && xb >= 605) {
					g[1] = 0;
				}
				if (yc < (550 - 50 * ile) && xc >= 605) {
					g[2]++;
					yc = h[2] + g[2] * g[2];
					xc = xc - 50;
					break;
				}
				if (yc < (480 - 50 * ile) && xc >= 605) {
					g[2] = 0;
				}
				if (yd < (550 - 50 * ile) && xd >= 605) {
					g[3]++;
					yd = h[3] + g[3] * g[3];
					xd = xd - 50;
					break;
				}

				if (yd < (480 - 50 * ile) && xd >= 605) {
					g[3] = 0;
				}
				if (ye < (550 - 50 * ile) && xe >= 605) {
					g[4]++;
					ye = h[4] + g[4] * g[4];
					xe = xe - 50;
					break;
				}
				if (ye < (480 - 50 * ile) && xe >= 605) {
					g[4] = 0;
				}
				if (yf < (550 - 50 * ile) && xf >= 605) {
					g[5]++;
					yf = h[5] + g[5] * g[5];
					xf = xf - 50;
					break;
				}
				if (yf < (480 - 50 * ile) && xf >= 605) {
					g[5] = 0;
				}
			}

		}
				
				EndPaint(hWnd, &ps);
				break;

			
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			}
			return 0;
		
	}


// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


