#include "ContainerViewElement.h"
namespace spider {
    ContainerViewElement::ContainerViewElement(Element *parent)
    : ViewElement(parent)
    {
        //ctor
        this->clipView = true;
    }

    ContainerViewElement::ContainerViewElement()
    : ViewElement()
    {
        //ctor
        this->clipView = true;
    }

    ContainerViewElement::~ContainerViewElement()
    {
        //dtor
    }
}
