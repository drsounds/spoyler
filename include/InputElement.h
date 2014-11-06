#ifndef INPUTELEMENT_H
#define INPUTELEMENT_H
#include "Element.h"
#include "GraphicsContext.h"
namespace spider {
class InputElement : public Element
{
private:
    public:
        InputElement();
        InputElement(Element *parent);
        virtual ~InputElement();
        virtual void draw(int x, int y, GraphicsContext *g);
    protected:
    private:
};
}
#endif // INPUTELEMENT_H
