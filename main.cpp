//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define UNSIGNED_INT unsigned int
//#define MAX(x,y) ((x)>(y))?(x):(y)
//
//int main() {
//    int number = (int) 345664343342;
//    int number1 = 234;
//    int* numberAddr = &number;
//    void* numberAddr1 = &number;
//    int numberAddr2 = number;
//
//    cout << "======" << endl;
//    cout << number << endl;
//    cout << number1 << endl;
//    cout << numberAddr << endl;
//    cout << numberAddr1 << endl;
//    cout << numberAddr2 << endl;
//
//    cout << "max number: " << MAX(number, number1);
//    cout << endl;
//
//    cout << "======" << endl;
//
//    vector<int> test(10, 0);
//    int j = 0;
//    do {
//        test.push_back(j);
//        j++;
//    } while (j < 10);
//
//    UNSIGNED_INT vectorSize = test.size();
//
//    cout << "vector size: " << vectorSize << endl;
//
//    for (int i = 0; i < test.size(); i++) {
//        cout << test[i] << endl;
//    }
//
//    cout << "======" << endl;
//
//    for (vector<int>::iterator cur = test.begin(); cur < test.end(); cur++) {
//        cout << *cur << endl;
//    }
//
//    cout << test.data();
//    cout << endl;
//    cout << "Hello, World!" << endl;
//    return 0;
//}


#include <windows.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <shlwapi.h>
#include <Shellapi.h>

#include "VectorContainer.h"

#pragma comment(lib,"ws2_32.lib")

#define UNSIGNED_INT unsigned int
#define MAX(x,y) ((x)>(y))?(x):(y)



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, World!");

    switch (message)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            // Here your application is laid out.
            // For this introduction, we just print out "Hello, World!"
            // in the top left corner.
            TextOutA(hdc,
                    45, 5,
                    greeting, _tcslen(greeting));
            // End application specific layout section.

            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
{
    std::vector<int> test(10, 0);
    int j = 0;
    do {
        test.push_back(j);
        j++;
    } while (j < 10);

    UNSIGNED_INT vectorSize = test.size();

    std::cout << "vector size: " << vectorSize << std::endl;


    static TCHAR szWindowClass[] = _T("win32app");
    static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = NULL; //LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = NULL; //LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
                _T("Call to RegisterClassEx failed!"),
                _T("Win32 Guided Tour"),
                1);

        return 1;
    }

    HINSTANCE hInst = hInstance; // Store instance handle in our global variable

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application dows not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
            szWindowClass,
            szTitle,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            500, 100,
            NULL,
            NULL,
            hInstance,
            NULL
    );

    // =============================================

    // Declare NOTIFYICONDATA details.
    // Error handling is omitted here for brevity. Do not omit it in your code.

    NOTIFYICONDATA nid = {0};


    nid.cbSize = sizeof(NOTIFYICONDATA);
    //nid.cbSize = NOTIFYICONDATA_V1_SIZE;

    nid.uID = 1234564;

    nid.cbSize = sizeof(nid);
    // set the window you want to recieve event messages
    nid.hWnd = hWnd;
//    nid.uFlags = NIF_ICON | NIF_TIP; // | NIF_GUID
    nid.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP| NIF_STATE;

//    nid.hIcon =
//            (HICON) LoadImage( hInstance, MAKEINTRESOURCE(IDI_ASTERISK),
//                    IMAGE_ICON,
//                    GetSystemMetrics(SM_CXSMICON),
//                    GetSystemMetrics(SM_CYSMICON),
//                    LR_DEFAULTCOLOR);

    // Note: This is an example GUID only and should not be used.
    // Normally, you should use a GUID-generating tool to provide the value to
    // assign to guidItem.
//    static const GUID myGUID =
//            {0x23977b55, 0x10e0, 0x4041, {0xb8, 0x62, 0xb1, 0x95, 0x41, 0x96, 0x36, 0x69}};
//    nid.guidItem = myGUID;
//
//    nid.guidItem = guid;
//
//    // This text will be shown as the icon's tooltip.
//    StringCchCopy(nid.szTip, ARRAYSIZE(nid.szTip), L"Test application");
    strcpy(nid.szTip, "Test application 2123");
//
//    // Load the icon for high DPI.
//    LoadIconMetric(hInst, MAKEINTRESOURCE(IDI_SMALL), LIM_SMALL, &(nid.hIcon));

    nid.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(32515));

    // Show the notification.
    Shell_NotifyIcon(NIM_ADD, &nid) ? S_OK : E_FAIL;


//    WSADATA wsaData;
//    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
//        std::cout << "WSAStartup failed.\n";
//        system("pause");
//        return 1;
//    }
//    SOCKET Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
//    struct hostent *host;
//    host = gethostbyname("www.google.com");
//    SOCKADDR_IN SockAddr;
//    SockAddr.sin_port=htons(80);
//    SockAddr.sin_family=AF_INET;
//    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
//    std::cout << "Connecting...\n";
//    if(connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr)) != 0){
//        std::cout << "Could not connect";
//        system("pause");
//        return 1;
//    }
//    std::cout << "Connected.\n";
//    send(Socket,"GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"),0);
//    char buffer[10000];
//    int nDataLength;
//    while ((nDataLength = recv(Socket,buffer,10000,0)) > 0){
//        int i = 0;
//        while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r') {
//            std::cout << buffer[i];
//            i += 1;
//        }
//    }
//    closesocket(Socket);
//    WSACleanup();


    // =============================================

    if (!hWnd)
    {
        MessageBox(NULL,
                _T("Call to CreateWindow failed!"),
                _T("Win32 Guided Tour"),
                1);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
            nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}