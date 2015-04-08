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
    SetMapMode(this->hDC, MM_TEXT);
    GetRandomRgn(this->hDC, this->currentRgn, SYSRGN);
    HRGN region = CreateRectRgn(rect.x / 96, rect.y / 96, rect.x + rect.width, rect.y + rect.height);

    OffsetRgn(region, rect.x, rect.y);
    int t = SelectClipRgn(this->hDC, region);
    if (t == ERROR) {
        exit(-1);
    }
    DeleteObject(region);
}

void Win32GraphicsContext::drawSkinImage(string resourceId, int x, int y, int w, int h) {
    Image *image = this->skin->getImage(resourceId, "");
    this->drawImage(image, x, y, w, h);
}

Win32GraphicsContext::Win32GraphicsContext(HWND hWnd, HDC hDC, WindowElement *window)
 : GraphicsContext(window) {
	this->hDC = hDC;
	this->hWnd = hWnd;
}

Win32GraphicsContext::~Win32GraphicsContext() {
}

void Win32GraphicsContext::declipRect() {
    SelectClipRgn(this->hDC, NULL);
    DeleteObject(this->currentRgn);

}
void Win32GraphicsContext::setOrigo(const int& x,const int& y) {
    OffsetViewportOrgEx(this->hDC, x / 96, y / 96, this->currentOffset);
}
void Win32GraphicsContext::restoreOrigo() {
    if (this->currentOffset != NULL)
        OffsetViewportOrgEx(this->hDC, this->currentOffset->x, this->currentOffset->y, NULL);
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

Image *Win32GraphicsContext::loadImage(const string& _bitmap) {
    cout << "Bitmap: " << _bitmap << "\n";

    char * dir = new char[1000];
    GetCurrentDirectory(1000, dir);

    string a = string(dir);
    a.append("\\");
    a.append(_bitmap);

    MessageBox(0, a.c_str(), "Path", MB_ICONSTOP | MB_OK);
    cout << "Bitmap path: " << a << "\r\n";
    HBITMAP hBitmap = (HBITMAP)LoadImage(NULL,(LPCSTR)a.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    if (hBitmap == NULL) {
        cout << GetLastError() << "\r\n";
        MessageBox(0, "Window Handler Invalid!", "Error!", MB_ICONSTOP | MB_OK);
    }
    BITMAP bm = {0};
    HDC dcBitmap = CreateCompatibleDC ( NULL );
    if (SelectObject(dcBitmap, hBitmap) == NULL) {
        MessageBox(0, "Window Handler Invalid!", "Error!", MB_ICONSTOP | MB_OK);
    }
    GetObject(hBitmap, sizeof(bm), &bm );
    LPSIZE siz;
    cout << bm.bmWidth << "px " << bm.bmHeight << "px \r\n";
    Image *image = new Image(bm.bmWidth, bm.bmHeight);
    BITMAPINFO bmpInfo;

    bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmpInfo.bmiHeader.biWidth = bm.bmWidth;
    bmpInfo.bmiHeader.biHeight = -bm.bmHeight;
    bmpInfo.bmiHeader.biPlanes = 1;
    bmpInfo.bmiHeader.biBitCount = 24;
    bmpInfo.bmiHeader.biCompression = BI_RGB;
    bmpInfo.bmiHeader.biSizeImage = 0;
    COLORREF* pixels = new COLORREF [ bm.bmWidth * bm.bmHeight ];
    GetDIBits(dcBitmap, hBitmap, 0, bm.bmHeight, pixels, &bmpInfo, DIB_RGB_COLORS );

    for (int i = 0; i < sizeof(pixels); i++) {
        pixel *pix = &image->pixels[i];
        pix->a = 255;
        pix->r = GetRValue(pixels[i]);
        pix->g = GetGValue(pixels[i]);
        pix->b = GetBValue(pixels[i]);
    }
    // Clean memory
    DeleteDC(dcBitmap);
    return image;

}

void Win32GraphicsContext::drawRectangle(int x1, int y1, int x2, int y2, Color *color) {
	HPEN hpen = CreatePen(PS_SOLID, 3, (RGB(255, 0, 0)));
	HGDIOBJ old = SelectObject(this->hDC, hpen);
	Rectangle(this->hDC, x1, y1, x2, y2);
	SelectObject(this->hDC, old);
	DeleteObject(hpen);
}
void Win32GraphicsContext::fillRectangle(int x1, int y1, int x2, int y2, Color *color) {
    if (color == NULL) {
        return;
    }
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
void Win32GraphicsContext::drawImage(Image *image, int x, int y, int width, int height) {

    // We use a handle so we only have to recreate the operating system specific bitmap once,
    // and then reuse it.
    BITMAP bm;

    if (image->handle == NULL) {
        cout << height;
        HDC memDC = CreateCompatibleDC(this->hDC);
        HBITMAP bitmap = CreateBitmap(image->width, image->height, 1, 32, image->pixels);

        SelectObject(memDC, bitmap);

        for (int x = 0; x < image->width; x++) {
            for (int y = 0; y < image->height; y++) {
                int _size = image->numPixels;
                // cout << "Count of pixels :" << _size << " Num of pixels: " << (x + (y * x)) << "\r\n";
                pixel pix = image->getPixel(x, y);
                COLORREF color = RGB(pix.r, pix.g, pix.b);


            }
        }

        DeleteObject(memDC);
        image->handle = (void *)bitmap;
    }
    HDC memDC = CreateCompatibleDC(this->hDC);
    HBITMAP bmp = (HBITMAP)SelectObject(memDC, (HBITMAP)image->handle);
    GetObject(bmp, sizeof(bm), &bm);

    if (true) {
        // BitBlt fill

        // StretchBlt topLeft corner
        if (true) {
            StretchBlt(this->hDC, x, y, image->leftBorder, image->topBorder, memDC, 0, 0, image->leftBorder, image->topBorder, SRCCOPY);

            // StretchBlt top
            StretchBlt(this->hDC, x + image->leftBorder, y, image->width - image->leftBorder - image->rightBorder, image->topBorder, memDC, image->leftBorder, 0, image->width - image->leftBorder - image->rightBorder, image->topBorder, SRCCOPY);

            // StretchBlt top right
            StretchBlt(this->hDC, x + width - image->rightBorder, y, image->rightBorder, image->topBorder, memDC, image->width - image->rightBorder, 0, image->rightBorder, image->height - image->bottomBorder, SRCCOPY);

            // StretchBlt bottom
            StretchBlt(this->hDC, x + width - image->rightBorder - image->leftBorder, y + height - image->bottomBorder, width - image->leftBorder - image->rightBorder, height - image->bottomBorder - image->topBorder, memDC, image->leftBorder, image->height - image->bottomBorder, image->width - image->leftBorder - image->rightBorder, image->bottomBorder, SRCCOPY);

            // StretchBlt Left bottom
            StretchBlt(this->hDC, x, y + height - image->bottomBorder, image->leftBorder, image->bottomBorder, memDC, 0, image->height - image->bottomBorder, image->leftBorder, image->bottomBorder, SRCCOPY);

            // StretchBlt Left
            StretchBlt(this->hDC, x, y + image->topBorder, image->leftBorder, image->height - image->topBorder - image->bottomBorder, memDC, 0, image->height - image->topBorder - image->bottomBorder, image->leftBorder, image->height - image->topBorder - image->bottomBorder, SRCCOPY);
        }
        StretchBlt(this->hDC, x + image->leftBorder, y + image->topBorder, width - image->leftBorder - image->rightBorder, height - image->topBorder - image->bottomBorder, memDC, image->leftBorder, image->topBorder, image->width - image->rightBorder - image->leftBorder, image->height - image->topBorder - image->bottomBorder, SRCCOPY);

    } else {
        StretchBlt(this->hDC, x, y, width, height, memDC, 0, 0, image->width, image->height, SRCCOPY);
    }
    DeleteObject(memDC);

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
    if (color == NULL) {
        return;
    }
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
    case WM_CHAR :
         switch (wParam)
         {

          case VK_RETURN:

            Element *sender = (*Win32GraphicsContext::hwnds)[hwnd];

            // Get text
            int textLength = GetWindowTextLength(hwnd) + 1;
            char *text = (char *)malloc(sizeof(char) * textLength);
            memset(text, 0, textLength);

            GetWindowText(hwnd, text, textLength);

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

