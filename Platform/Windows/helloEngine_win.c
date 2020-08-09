#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    // the handle for the window, filled by a function
    HWND hWnd;
    // the struct that holds information for the window class
    WNDCLASSEX wc;
    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("WindowClass1");

    // regists the window class
    RegisterClassEx(&wc);

    // create the window and use the result ad the handle
    hWnd = CreateWindowEx(0, _T("WindowClass1"), // name of the window class
        _T("Hello, Engine!"), // title of the window
        WS_OVERLAPPEDWINDOW, // window style
        300, // x-pos of the window
        300, // y-pos of the window
        500, // width of the window
        400, // height of the window
        NULL, // parent window
        NULL, // menus
        hInstance, // application handle
        NULL // multiple windows
    );

    // display the window on the screen
    ShowWindow(hWnd, nCmdShow);

    // enter the main loop;
    // the struct that holds windows event messages
    MSG msg;

    // wait for the next message in the queue, store the reuslt in 'msg'
    while (GetMessage(&msg, NULL, 0, 0))
    {
        // translate keystroke messages into the right format
        TranslateMessage(&msg);
        // send the message to the WindowProc function
        DispatchMessage(&msg);
    }

    // return this part of the WM_QUIT message to Windows
    return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and choose a code to run for the given message
    switch(message)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            RECT rec = { 20, 20, 60, 80 };
            HBRUSH brush = (HBRUSH) GetStockObject(BLACK_BRUSH);
            FillRect(hdc, &rec, brush);
            EndPaint(hWnd, &ps);
        }
        break;
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        break;
    }

    // handle any messages which fall through the switch statement
    return DefWindowProc(hWnd, message, wParam, lParam);
}