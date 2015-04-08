#ifndef VIEWELEMENT_H
#define VIEWELEMENT_H
#include "VBoxElement.h"
#include "Uri.h"
namespace spider {
    class ViewElement : public VBoxElement
    {
        public:
            string loadView(string view);
            void request(string uri);
            ViewElement();
            ViewElement(Element *parent);
            virtual ~ViewElement();
            virtual void navigate(string uri);
            virtual bool acceptsUri(string uri) {
                return false;
            }
            virtual void scroll(int scrollX, int scrollY, int mouseX, int mouseY);
            void pack();
        protected:
        private:
    };
}
#endif // VIEWELEMENT_H
