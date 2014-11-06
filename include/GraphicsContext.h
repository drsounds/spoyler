#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H
#include "FontStyle.h"
#include "libspider.h"
#include "Color.h"
#include "Element.h"
namespace spider {
    class Element;
    class WindowElement;
    class GraphicsContext {
	protected:
		FontStyle *fontStyle;
        WindowElement *window;
	public:
        GraphicsContext(WindowElement *window);
        virtual void setClip(rectangle rect) {}
		virtual void drawLine(int x, int y, int x2, int y2, Color *color) {}
		virtual void drawRectangle(int x, int y, int w, int h, Color *color) {}
		virtual void fillRectangle(int x, int y, int w, int h, Color *color) {}
		virtual void drawImage(void *image, int x, int y, int w, int h) {}
		virtual void drawControl(int x, int y, int w, int h, char *name) {}
		virtual void drawString(char *text, FontStyle *fs, Color *color, int x, int y, int w, int h) {}
		virtual void invalidateRegion(rectangle region) {}
		virtual void drawHTMLText(char *html, FontStyle *fs, Color *color, int x, int y, int w, int h) {}
		virtual rectangle measureString(char *text, spider::FontStyle *font) {}
		void setFontStyle(spider::FontStyle *fs) {
			this->fontStyle = fs;
		}
		FontStyle *getFontStyle() {
			return this->fontStyle;
		}
        virtual void drawControl(char *control, Element *srcElement, int x, int y, int w, int h) {}
        virtual void drawInputElement(Element *srcElement, int x, int y, int w, int h) {}
		virtual void setOrigo(const int& x, const int& y);
	};
}
#endif // GRAPHICSCONTEXT_H
