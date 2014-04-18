#pragma once

#ifndef H_WIN32SPIDER
#define H_WIN32SPIDER

#include <Windows.h>
#include <wingdi.h>
#include <map>
#include "Color.h"
#include "GraphicsContext.h"
using namespace std;
namespace spider {
    class WindowElement;
	COLORREF toWin32Color(spider::Color color);

	class Win32GraphicsContext : public GraphicsContext {
	private:
		HDC hDC;
		HWND hWnd;
		map<string, HWND> *controls;
	public:
		Win32GraphicsContext(HWND hWnd, HDC hDC, WindowElement *window);
		~Win32GraphicsContext();
		void setClip(rectangle rect);
		void drawLine(int x1, int y1, int w, int h, spider::Color *color);
		void drawImage(void *image, int x1, int y1, int w, int h);
		void drawRectangle(int x1, int y1, int w, int h, spider::Color *color);
		void fillRectangle(int x1, int y1, int w, int h, spider::Color *color);
		void invalidateRegion(rectangle region);
		void drawString(char *text, spider::FontStyle *fontStyle, spider::Color *color,int x, int y, int w, int h);
		void setFontStyle(spider::FontStyle *fs);
		void drawControl(int x, int y, int w, int h, char *name);
		void setOrigo(const int& x, const int& y);
		void drawHTMLText(char *html, FontStyle *fs, Color *color, int x, int y, int w, int h);
		rectangle measureString(char *text, spider::FontStyle *font);
	};
};
#endif
