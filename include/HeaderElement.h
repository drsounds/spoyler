#ifndef HEADERELEMENT_H
#define HEADERELEMENT_H
#include "HBoxElement.h"
#include "ImageElement.h"
#include "TitleElement.h"
namespace spider {
    class HeaderElement : public HBoxElement
    {
        public:
            HeaderElement();
            HeaderElement(Element *parent);
            virtual ~HeaderElement();
            TitleElement *title;
            ImageElement *image;
            virtual string getType() {
                return "header";
            }
        protected:
        private:
    };
}

#endif // HEADERELEMENT_H
