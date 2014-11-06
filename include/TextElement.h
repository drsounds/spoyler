#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H
#include "Element.h"
namespace spider {
class TextElement : public Element
{
    public:
        TextElement(Element *parent);
        void draw(int x, int y, GraphicsContext *g);
        virtual ~TextElement();
    protected:
    private:
};
}
#endif // TEXTELEMENT_H
