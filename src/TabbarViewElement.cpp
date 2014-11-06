#include "TabbarViewElement.h"
namespace spider {
    int tabbar_tabselected(SPType *sender, EventArgs *e) {
        TabBarEventArgs *args = (TabBarEventArgs *)e;
        string uri = *args->tab->getUri();
        TabBarElement *tabView = (TabBarElement *)sender;
        TabbarViewElement *tabbarView = (TabbarViewElement *)tabView->parent;
        tabbarView->navigate(uri);
    }
    TabbarViewElement::TabbarViewElement()
     : ViewElement() {

    }
    void TabbarViewElement::mousedown(int mouseButton, int x, int y) {
        Element::mousedown(mouseButton, x, y);
    }
    TabbarViewElement::TabbarViewElement(Element *parent)
     : ViewElement::ViewElement(parent)
    {
        //ctor
        this->tabBar = new TabBarElement(parent);
        this->viewStack = new ViewStackElement(parent);
        this->appendChild(this->tabBar);
        this->tabBar->setHeight(20);
        this->tabBar->set("height", "20");
        this->tabBar->addEventListener(string("tabselected"), &tabbar_tabselected);
        this->viewStack->set("flex", "1");
        this->appendChild(this->viewStack);
    }
    bool TabbarViewElement::acceptsUri(string uri) {
        return false;
    }
    void TabbarViewElement::navigate(string uri) {
        this->viewStack->navigate(uri);
    }
    TabbarViewElement::~TabbarViewElement()
    {
        delete this->tabBar;
        delete this->viewStack;
    }
}
