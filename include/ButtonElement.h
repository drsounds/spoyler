#ifndef BUTTONELEMENT_H
#define BUTTONELEMENT_H
#include "Element.h"
namespace spider {
	class ButtonElement : public Element {
	public:
        ButtonElement(Element *parent) : Element(parent) {

	    }
		ButtonElement();
		void draw(int x, int y, spider::GraphicsContext *c);
	};
}


#endif // BUTTONELEMENT_H
