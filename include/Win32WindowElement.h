#pragma once
#ifndef H_SPIDER
#define H_SPIDER
#include <Windows.h>
#include "MainWindowElement.h"
#include <string>
#include "WindowElement.h"
#define MAX_LOADSTRING 100
namespace spider {
	class Win32WindowElement : public WindowElement {
	private:

		HINSTANCE hInst;								// current instance
		HDC memHDC;
		HWND hWnd;
        MainWindowElement *mainWindow;
	public:
	    void invalidateRegion(rectangle rect);
	    GraphicsContext *createGraphics();
        MainWindowElement *getMainWindow() {
            return this->mainWindow;
        }
	    void setHandle(HWND hWnd) {
            this->hWnd = hWnd;
	    }
	    void navigate(string uri);
		HBITMAP bufferBitmap;
		void draw(spider::GraphicsContext *graphics);
		void Show();
		void Hide();
		Win32WindowElement();
		Win32WindowElement(HDC hdc);
		void SampleLayout();
		ATOM MyRegisterClass(HINSTANCE hInstance);
		BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
		HDC getMemDC() {
			return this->memHDC;
		}
		HWND getHandle() {
 			return this->hWnd;
		}
		void scroll(int x, int y);
		void scrollTo(int x, int y);
		virtual void scroll(int x, int y, int mouseX, int mouseY);
		void pack();
	};
}
#include "libspider.h"
#endif
