#include "InputElement.h"
namespace spider {
InputElement::InputElement()
{
    //ctor
}

InputElement::~InputElement()
{

}
InputElement::InputElement(Element *parent)
    : Element(parent) {

}

void InputElement::draw(int x, int y, GraphicsContext *g) {
    Element::draw(x, y, g);
    g->drawInputElement(this, x, y, this->getWidth(), this->getHeight());
}
}
