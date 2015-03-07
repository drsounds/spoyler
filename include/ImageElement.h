#ifndef IMAGEELEMENT_H
#define IMAGEELEMENT_H
#include "Element.h"
namespace spider {
class ImageElement : public Element
{
    public:
        ImageElement(Element *parent);
        virtual ~ImageElement();
        void draw(int x, int y, GraphicsContext *g);
        virtual string getType() {
            return "img";
        }
    protected:
    private:
};
}

#endif // IMAGEELEMENT_H
