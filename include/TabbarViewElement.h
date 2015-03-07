#ifndef TABBARVIEWELEMENT_H
#define TABBARVIEWELEMENT_H

#include "Element.h"
#include "ViewElement.h"
#include "TabBarElement.h"
#include "ViewStackElement.h"
namespace spider {
class TabbarViewElement : public ViewElement
{
    public:
        virtual string getType() {
            return "table";
        }
        TabbarViewElement();
        TabbarViewElement(Element *parent);
        virtual ~TabbarViewElement();
        virtual void navigate(string uri);
        virtual bool acceptsUri(string uri);
        void mousedown(int mouseButton, int x, int y);
    protected:
        ViewStackElement *viewStack;
        TabBarElement *tabBar;

    private:
};
}

#endif // TABBARVIEWELEMENT_H
