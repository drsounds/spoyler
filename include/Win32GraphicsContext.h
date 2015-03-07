#pragma once

#ifndef H_WIN32SPIDER
#define H_WIN32SPIDER

#include <Windows.h>
#include <wingdi.h>
#include <map>
#include "Color.h"
#include "Element.h"
#include "GraphicsContext.h"
#include "InputEventArgs.h"
#include <map>
using namespace std;
LRESULT CALLBACK subEditProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace spider {

    class WindowElement;
	COLORREF toWin32Color(spider::Color color);
	class Win32GraphicsContext : public GraphicsContext {
	private:
		HDC hDC;
		HWND hWnd;
	public:
		static map<Element *, HWND> *controls;
		static map<HWND, Element *> *hwnds;
		Win32GraphicsContext(HWND hWnd, HDC hDC, WindowElement *window);
		~Win32GraphicsContext();
        Image *loadImage(const string& bitmap);
		void setClip(rectangle rect);
		void drawLine(int x1, int y1, int w, int h, spider::Color *color);
		void drawImage(Image *image, int x1, int y1, int w, int h);
		void drawRectangle(int x1, int y1, int w, int h, spider::Color *color);
		void fillRectangle(int x1, int y1, int w, int h, spider::Color *color);
        void drawControl(char *control, Element *elm, int x, int y, int w, int h);
		void invalidateRegion(rectangle region);
		void drawString(char *text, spider::FontStyle *fontStyle, spider::Color *color,int x, int y, int w, int h);
		void drawInputElement(Element *elm, int x, int y, int w, int h);
		void setFontStyle(spider::FontStyle *fs);
		void setOrigo(const int& x, const int& y);
		void drawHTMLText(char *html, FontStyle *fs, Color *color, int x, int y, int w, int h);
		rectangle measureString(char *text, spider::FontStyle *font);
	};
};
#endif
