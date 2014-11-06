#ifndef TABBARELEMENT_H
#define TABBARELEMENT_H
#include "Element.h"
#include <vector>
namespace spider {
class TabBarElement;
class Tab {
protected:
public:
    string *id;
    string *name;
    string *uri;
    TabBarElement *tabBar;
    TabBarElement *getTabBar() {
        return this->tabBar;
    }
    string *getId() {
        return this->id;
    }
    string *getName() {
        return this->name;
    }
    string *getUri() {
        return this->uri;
    }
    Tab(TabBarElement *tabBar, string *name, string *id, string *uri);
    ~Tab();
};

class TabBarEventArgs : public EventArgs {
public:
    TabBarEventArgs(Tab *tab);
    Tab *tab;
};

class TabBarElement : public Element
{
    public:
        TabBarElement();
        TabBarElement(Element *parent);
        void addTab(string *id, string *name, string *uri);
        virtual ~TabBarElement();
        void mousedown(int mouseButton, int x, int y);
        void draw(int x, int y, GraphicsContext *g);
        vector<Tab *> *getTabs() {
            return this->tabs;
        }
        Tab *activeTab;
        vector<Tab *> *tabs;
    protected:
    private:
};
}


#endif // TABBARELEMENT_H
