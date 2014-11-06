#pragma once
#include "Win32GraphicsContext.h"
namespace spider {
WNDPROC oldEditProc;
map<Element *, HWND> *Win32GraphicsContext::controls = new map<Element *, HWND>;
map<HWND, Element *> *Win32GraphicsContext::hwnds = new map<HWND, Element *>;
COLORREF toWin32Color(Color color) {
	return NULL;
}
void Win32GraphicsContext::setClip(rectangle rect) {
    if (rect.width == 0 || rect.height == 0) {
        SelectClipRgn(this->hDC, NULL);
    }
    HRGN region = CreateRectRgn(rect.x, rect.y, rect.width, rect.height);


    SelectClipRgn(this->hDC, region);
}
Win32GraphicsContext::Win32GraphicsContext(HWND hWnd, HDC hDC, WindowElement *window)
 : GraphicsContext(window) {
	this->hDC = hDC;
	this->hWnd = hWnd;
}
Win32GraphicsContext::~Win32GraphicsContext() {

}
void Win32GraphicsContext::setOrigo(const int& x,const int& y) {
//	spider::GraphicsContext::setOrigo(x, y);
}
void Win32GraphicsContext::drawLine(int x1, int y1, int x2, int y2, Color *color) {


}
void Win32GraphicsContext::drawHTMLText(char *html, FontStyle *fs, Color *color, int x, int y, int w, int h) {

}


void Win32GraphicsContext::invalidateRegion(spider::rectangle rect) {
    LPRECT rgn;
    rgn->left = rect.x;
    rgn->right = rect.width + rect.x;
    rgn->bottom = rect.y + rect.height;
    rgn->top = rect.y;
    InvalidateRect(this->hWnd, rgn, TRUE);
}
void Win32GraphicsContext::drawRectangle(int x1, int y1, int x2, int y2, Color *color) {
	HPEN hpen = CreatePen(PS_SOLID, 3, (RGB(255, 0, 0)));
	HGDIOBJ old = SelectObject(this->hDC, hpen);
	Rectangle(this->hDC, x1, y1, x2, y2);
	SelectObject(this->hDC, old);
	DeleteObject(hpen);
}
void Win32GraphicsContext::fillRectangle(int x1, int y1, int x2, int y2, Color *color) {
	HBRUSH hpen = CreateSolidBrush((RGB(color->getR(), color->getG(), color->getB())));
	HGDIOBJ old = SelectObject(this->hDC, hpen);
	RECT r;
	r.left = x1;
	r.right =  x1 + x2;
 	r.bottom =  y1 + y2;
	r.top = y1;
	FillRect(this->hDC, &r, hpen);

	SelectObject(this->hDC, old);
	DeleteObject(hpen);
}
void Win32GraphicsContext::drawImage(void *image, int x1, int y1, int x2, int y2) {
    /*HDC *memDC = CreateCompatibleDC(this->hDC);
    HBITMAP bitmap = CreateCompatibleBitmap(memDC, image->width, image->height);
    SelectObject(memDC, bitmap);

    for (int x = 0; x < image->width; x++) {
        for (int y = 0; y < image->height; y++) {
            pixel *pixel = image->pixels[x * y];
            COLORREF color = RGB(pixel->r, pixel->g, pixel->b);
            SetPixel(memDC, x, y, color);
        }
    }
    BitBlt(this->hDC, x1, y1, x2, y2, memDC, 0, 0, SRCCOPY);
    DeleteObject(bitmap);
    DeleteDC(memDC);*/
    this->fillRectangle(x1, y1, x2, y2, new Color(255, 255, 255, 255));
}

rectangle Win32GraphicsContext::measureString(char *text, FontStyle *fs) {
#define CLEARTYPE_QUALITY 0x05
#define ANTIALIASED_QUALITY 0x04
    SIZE sizeText;
    int len = lstrlen(text);
    HFONT font = CreateFont(fs->getHeight(), fs->getHeight() / 2, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS,  CLIP_MASK, CLEARTYPE_QUALITY , FF_MODERN | VARIABLE_PITCH, TEXT(fs->getFamily()));
    SelectObject(this->hDC, font);
    GetTextExtentPoint32(this->hDC, (char *)text, len, &sizeText);
    DeleteObject(font);
    spider::rectangle rect;
    rect.width = sizeText.cx;
    rect.height = sizeText.cy;
    rect.x = 0;
    rect.y = 0;
    return rect;
}
void Win32GraphicsContext::drawString(char *text, FontStyle *fs, spider::Color *color, int x, int y, int w, int h) {
#define CLEARTYPE_QUALITY 0x05
#define ANTIALIASED_QUALITY 0x04
    RECT rect;
    rect.left = x;
    rect.right = x + w;
    rect.top = y;
    rect.bottom = y + h;
    HFONT font = CreateFont(fs->getHeight(), fs->getHeight() / 2, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS,  CLIP_MASK, CLEARTYPE_QUALITY , FF_MODERN | VARIABLE_PITCH, TEXT(fs->getFamily()));
    SetBkMode(this->hDC, TRANSPARENT);
    COLORREF col = RGB(color->getR(), color->getG(), color->getB());
    SetTextColor(this->hDC, col);
    SelectObject(this->hDC, font);
    //TextOut(this->hDC, x, y, (LPCSTR)text, sizeof(text) * sizeof(char));

    DrawText(this->hDC, (LPCSTR)text, lstrlen(text), &rect, 0);
    DeleteObject(font);
}

LRESULT CALLBACK subEditProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   switch (msg)
   {
    case WM_KEYDOWN:
         switch (wParam)
         {
          case VK_RETURN:

            Element *sender = (*Win32GraphicsContext::hwnds)[hwnd];

            // Get text
            int textLength = GetWindowTextLength(hwnd);
            char *text = (char *)malloc(sizeof(char) * textLength);
            memset(text, 0, sizeof(text));

            GetWindowText(hwnd, text, sizeof(text));

            sender->notify("enter", sender, new InputEventArgs(string(text)));
            return 0;

         WNDPROC oldEditProc; //Do your stuff
              break;  //or return 0; if you don't want to pass it further to def proc
          //If not your key, skip to default:
         }
    default:
         return CallWindowProc(oldEditProc, hwnd, msg, wParam, lParam);
   }
   return 0;
}


void Win32GraphicsContext::drawControl(char *control, Element *elm, int x, int y, int w, int h) {
    HWND hwnd;
    int count_controls = this->controls->count(elm);
    if (count_controls > 0) {
        hwnd = (*Win32GraphicsContext::controls)[elm];
        //SetWindowPos(hwnd, 0, x, y, w, h, 0);
    } else {
        hwnd = CreateWindow(control, 0, WS_CHILD|WS_VISIBLE, x, y / 4, w, h / 4, this->hWnd, 0, NULL, 0);
        controls->insert(std::pair<Element *, HWND>(elm, hwnd));
        HFONT font = CreateFont(8, 4, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS,  CLIP_MASK, CLEARTYPE_QUALITY , FF_MODERN | VARIABLE_PITCH, "MS Sans Serif");

        SendMessage(hwnd, WM_SETFONT, WPARAM(font), TRUE);
        (*Win32GraphicsContext::hwnds)[hwnd] = elm;
        oldEditProc = (WNDPROC)SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)subEditProc);
    }
}

void Win32GraphicsContext::drawInputElement(Element *elm, int x, int y, int w, int h) {
    this->drawControl("EDIT", elm, x, y, w, h);
}

}

