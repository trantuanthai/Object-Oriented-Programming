// 20280082_20280108.cpp : Defines the entry point for the application.
//
#include "framework.h"
#include "20280082_20280108.h"
#define MAX_LOADSTRING 100
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY2028008220280108, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2028008220280108));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2028008220280108));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2028008220280108);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    WCHAR msg[][50] = { L"NOT INTERSECT!", L"INTERSECT!" };
    static wchar_t szInfor[1000] = L"";
    static HBRUSH hbr1, hbr2;
    static HPEN hPenDot, penBorder1, penBorder2;
    static const int MAX_SHAPE = 50;
    RECT rt;

    // Toa do cac dinh cua hinh tam giac thu 1
    static MyPoint tr[] = {
       MyPoint(150, 200),
       MyPoint(300, 250),
       MyPoint(400, 100),
    };

    // Toa do cac dinh cua hinh chu nhat thu 1
    static MyPoint re[] = {
       MyPoint(250, 300),
       MyPoint(400, 100)
    };
    // Toa do cac dinh cua da giac thu 1
    static MyPoint p[] = {
       MyPoint(50, 50),
       MyPoint(50, 150),
       MyPoint(100,150),
       MyPoint(100, 200),
       MyPoint(200,100)
    };

    // Toa do cac dinh cua hinh vuong thu 1
    static MyPoint sq[] = { MyPoint(250, 300) };

    // Mang chua cac doi tuong thu 1
    static MyShape* s[] = {
        new MyTriangle(3,tr),
        new MyRectangle(4, re),
        new MyCircle(500, 300, 100),
        new MyPolygon(5, p),
        new MyEllipse(500, 300, 200, 100),
        new MySemiCircle(350, 100, 150),
        new MySquare(4, sq, 150)
    };

    // Toa do hinh tam giac thu 2
    static MyPoint tr1[] = {
      MyPoint(300, 400),
      MyPoint(500, 300),
      MyPoint(400, 200),
    };

    // Toa do hinh chu nhat thu 2
    static MyPoint re1[] = {
        MyPoint(500, 100),
        MyPoint(300, 200)
    };

    // Toa do da giac thu 2
    static MyPoint q[] = {
       MyPoint(50, 50),
       MyPoint(50, 150),
       MyPoint(100,150),
       MyPoint(100, 200),
       MyPoint(200,100),
       MyPoint(75,100)
    };

    // Toa do hinh vuong thu 2
    static MyPoint sq1[] = { MyPoint(100, 150) };

    // Mang chu cac doi tuong thu 2
    static MyShape* s1[] = {
       new MyPolygon(6, q),
       new MyCircle(400, 200, 100),
       new MyEllipse(400, 300, 200, 75),
       new MyRectangle(4,re1),
       new MySemiCircle(400, 200, 100),
       new MyTriangle(3,tr1),
       new MySquare(4, sq1, 100)
    };

    static int h = 0;
    static int h1 = 0;
    const int n = sizeof(s) / sizeof(s[0]);
    const int n1 = sizeof(s1) / sizeof(s1[0]);
    static MyShape* pS = s[h];
    static MyShape* pS1 = s1[h1];

    switch (message)
    {
    case WM_CREATE:
    {
        GetClientRect(hWnd, &rt);
        hbr1 = CreateSolidBrush(RGB(0, 238, 0));
        hbr2 = CreateSolidBrush(RGB(255, 127, 0));
        penBorder1 = CreatePen(PS_SOLID, 2, RGB(0, 238, 0));
        penBorder2 = CreatePen(PS_SOLID, 2, RGB(255, 127, 0));
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_CHAR:
   
        switch (TCHAR(wParam))
        {
        case '+': // Phong to
            pS1->Scale(1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '-': // Thu nho
            pS1->Scale(1/1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;

    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_SPACE: // Thay doi doi tuong di chuyen
            if (++h1 == n1) {
                h1 = 0;
            }
            pS1 = s1[h1];
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_TAB: // Thay doi doi tuong hinh dung im
            if (++h == n1) {
                h = 0;
            }
            pS = s[h];
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT: // Di chuyen qua phai
            pS1->Move(20, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT: // Di chuyen qua trai
            pS1->Move(-20, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP: // Di chuyen len tren
            pS1->Move(0, -20);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN: // Di chuyen xuong duoi
            pS1->Move(0, 20);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        swprintf_s(szInfor, L"ARROW keys (Move)  -  TAB key (Change object of shape 1)  -  'SPACE key' (Change object of shape 2)  -  '+' key (Zoom in)  -  '-' key (Zoom out)");
        GetClientRect(hWnd, &rt);
        DrawText(hdc, szInfor, lstrlen(szInfor), &rt, DT_CENTER | DT_BOTTOM | DT_SINGLELINE);
        SelectObject(hdc, penBorder1);
        pS->Draw(hdc); // Ve doi tuong thu 1
        SelectObject(hdc, penBorder2);
        pS1->Draw(hdc); // Ve doi thuong thu 2
        RECT r;
        GetClientRect(hWnd, &r);
        // Kiem tra su giao nhau cua 2 doi tuong
        int idx = pS1->Intersection(pS, hdc);
        DrawText(hdc, msg[idx], lstrlen(msg[idx]), &r, DT_CENTER | DT_BOTTOM);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        delete[] pS;
        delete[] pS1;
        DeleteObject(hbr1);
        DeleteObject(hbr2);
        PostQuitMessage(0);
        break;
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
