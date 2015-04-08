#ifndef CONTAINERVIEWELEMENT_H
#define CONTAINERVIEWELEMENT_H
#include "ViewElement.h"
namespace spider {
    class ContainerViewElement : public ViewElement
    {
        public:
            ContainerViewElement(Element *parent);
            ContainerViewElement();
            virtual ~ContainerViewElement();
        protected:
        private:
    };
}

#endif // CONTAINERVIEWELEMENT_H
