#include "ResourceElement.h"
namespace spider {
    ResourceElement::ResourceElement(Resource *resource, Element *parent)
     : Element(parent)
    {
        //ctor
        this->resource = resource;
    }
    void ResourceElement::Draw(int x, int y, GraphicsContext *g) {
        FontStyle *font = (FontStyle *)this->getFont();
        Color *fgColor = (Color *)this->getAttributeObj("fgcolor");
        Color *bgColor = (Color *)this->getAttributeObj("bgcolor");
        if (this->resource != NULL) {

            // Draw title
            string *name = this->resource->getName();
            char *title = (char *)name->c_str();
            rectangle txtSize = g->measureString(title, font);
            int top = (this->getHeight() / 2) - (txtSize.height / 2);
            g->drawString(title, font, fgColor, x + 10, top, this->getWidth(), this->getHeight());

            // Draw separator
            g->drawLine(x, this->getHeight()-1 + y, this->getWidth() + x, this->getHeight()-1 + y, fgColor);
        }
    }
    ResourceElement::~ResourceElement()
    {
        //dtor
    }
}
