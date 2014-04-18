#ifndef RESOURCEELEMENT_H
#define RESOURCEELEMENT_H

#include "Element.h"
#include "Resource.h"
namespace spider {
class ResourceElement : public Element
{
    public:
        ResourceElement(Resource *resource, Element *parent);
        virtual ~ResourceElement();
        void Draw(int x, int y, GraphicsContext *g);
    protected:
        Resource *resource;
    private:
};
}

#endif // RESOURCEELEMENT_H
