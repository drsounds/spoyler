#include "TextElement.h"
namespace spider {
TextElement::TextElement(Element *parent)
 : Element(parent)
{
    //ctor
}
void TextElement::draw(int x, int y, GraphicsContext *g) {
    Color *bgcolor = (Color *)this->getAttributeObj("bgcolor");
    Color *fgcolor = (Color *)this->getAttributeObj("fgcolor");
    FontStyle *font = this->getFont();
    g->drawString(this->data, font, fgcolor, x ,y , this->getWidth(), this->getHeight());
}
TextElement::~TextElement()
{
    //dtor
}
}
