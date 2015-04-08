#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "libspider.h"
#include "Win32WindowElement.h"
#include "Win32GraphicsContext.h"
#include "main.h"



/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
using namespace spider;
Win32WindowElement *window  = new Win32WindowElement();
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
/*!
 * \source http://stackoverflow.com/questions/12689142/win32-api-command-line-arguments-parsing
 */
void process_arguments(char** argv, process_option_cb process_option, process_value_cb process_value) {
    int i;
    char *key, *value;

    for( i = 0; i < sizeof(argv); i++ ) {
        if( *argv[i] == '/' ) {
            key = argv[i] + 1;
            value = strchr(key, ' ');
            if( value != NULL ) *value++ = 0;
            process_option( key, value );
        } else {
           // if(&process_value != NULL)
           // process_value( argv[i] );
        }
    }
}

void process_option(char *key, char *val) {
    if (strcmp(key, "uri") == 0) {
        window->navigate(string(val));
    }
}


int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{



    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

   // window->setHandle(hwnd);
    window->SampleLayout();
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW | WS_VSCROLL, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Pass window arguments **/
    // int len_args = 0;
    // process_arguments((char **)CommandLineToArgvW(GetCommandLineW(), &len_args), &process_option, NULL);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

Win32GraphicsContext *gc2;
RECT clientRect;
PAINTSTRUCT ps;
HDC memDC ;
HBITMAP btp ;
HGDIOBJ t ;
HGDIOBJ f;
HDC hdc;
int mouseX = 0, mouseY = 0;
BOOL CALLBACK cw (HWND hWnd, LPARAM lParam) {
    SendMessage(hWnd, WM_PAINT, 0, 0);
}
LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
    // Fixed flicker from http://snipd.net/double-buffering-with-a-back-buffer-in-vc
    RECT clientRect;
	int iPosX, iPosY;
	GetClientRect(hWnd,&clientRect);
    window->setHandle(hWnd);
    iPosX = LOWORD(lParam);
    iPosY = HIWORD(lParam);
    GetClientRect(hWnd,&clientRect);
	switch (message)
	{
    case WM_CREATE:
        {


        GetClientRect(hWnd,&clientRect);
        memDC = CreateCompatibleDC(NULL);
        hdc = GetDC(hWnd);
        btp = CreateCompatibleBitmap(hdc, 10000, 10000);
        SelectObject(memDC, btp);
        gc2 = new Win32GraphicsContext(hWnd, memDC, window);
        window->skin = new Skin("skin.bmp", gc2);

        ReleaseDC(hWnd, hdc);
        ShowScrollBar(hWnd, SB_BOTH, false);
        break;
        }
    case WM_MOUSEMOVE:
        mouseX = iPosX;
        mouseY = iPosY;
        break;
	case WM_SIZE:
        GetClientRect(hWnd,&clientRect);
	    InvalidateRect(hWnd,&clientRect, TRUE);
	    window->pack();
		break;
    case WM_LBUTTONUP:

		window->click(0, iPosX, iPosY);
		window->mouseup(0, iPosX, iPosY);
		break;
	case WM_LBUTTONDOWN:
		window->mousedown(0, iPosX, iPosY);
		break;
    case WM_MOUSEWHEEL:
        {
            int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
            if (zDelta > 0) {
                window->scroll(0, -10, mouseX, mouseY);
            } else {
                window->scroll(0, 10, mouseX, mouseY);
            }

        }
        break;
    case WM_VSCROLL:
        {
            int scrollDir = LOWORD(wParam);
            int scrollPos = HIWORD(wParam);
            if (scrollDir == SB_LINEDOWN) {
                window->scroll(0, 2);
            }
        }
        break;
    case WM_HSCROLL:
        {
            int scrollDir = LOWORD(wParam);
            int scrollPos = HIWORD(wParam);
            if (scrollDir == SB_RIGHT) {
                window->scroll(2, 0);
            }
        }
        break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		//case IDM_EXIT:
			//DestroyWindow(hWnd);
			//break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        t = SelectObject(memDC, btp);

        window->draw(gc2);
        BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, memDC, 0, 0, SRCCOPY);
        EnumChildWindows(hWnd, &cw, 0);
        InvalidateRect(hWnd,NULL,false);
        EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
