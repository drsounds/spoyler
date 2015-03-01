#ifndef HEADERELEMENT_H
#define HEADERELEMENT_H
#include "HBoxElement.h"
#include "TextElement.h"
namespace spider {
    class HeaderElement : public HBoxElement
    {
        public:
            HeaderElement();
            HeaderElement(Element *parent);
            virtual ~HeaderElement();

        protected:
            TextElement *parent;
        private:
    };
}

#endif // HEADERELEMENT_H
