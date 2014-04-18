#include "ImageElement.h"
namespace spider {
ImageElement::ImageElement(Element *parent)
 : Element(parent)
{
    //ctor
}
void ImageElement::Draw(int x, int y, GraphicsContext *g) {
    g->drawImage(NULL, x, y, this->getWidth(), this->getHeight());
}
ImageElement::~ImageElement()
{
    //dtor
}
}
