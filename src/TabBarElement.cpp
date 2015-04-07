#include "TabBarElement.h"
namespace spider {

Tab::Tab(TabBarElement *tabBar, string *name, string *id, string *uri) {
    this->tabBar = tabBar;
    this->name = name;
    this->id = id;
    this->uri = uri;
}

int tabbar_mousedown(SPType *sender, EventArgs *e) {
    TabBarElement *tabBar = (TabBarElement *)sender;
    MouseEventArgs *me = (MouseEventArgs *)e;
    int x = tabBar->getAbsoluteBounds() != NULL ? me->getX() - tabBar->getAbsoluteBounds()->y : me->getX();
    int y = tabBar->getAbsoluteBounds() != NULL ? me->getY() - tabBar->getAbsoluteBounds()->y : me->getY();
    int left = 0;
    ;
    for(std::vector<Tab *>::iterator it = tabBar->tabs->begin(); it != tabBar->tabs->end(); ++it) {
        Tab *tab = (Tab *)dynamic_cast<Tab *>(*it);
        string *title = tab->getName();
        string *id = tab->getId();
        string *uri = tab->getUri();
        FontStyle *font = (FontStyle *)tabBar->getAttributeObj("font");
        GraphicsContext *g = tabBar->createGraphics();
        rectangle strSize = g->measureString((char *)title->c_str(), font);
        int width = 20 + strSize.width + 20;
        if (x > left && x < left + width) {
            tabBar->activeTab = tab;
            TabBarEventArgs *args = new TabBarEventArgs(tab);
            tabBar->notify(string("tabselected"), (SPType *)tabBar, (EventArgs *)args);

        }

        left += width;
    }
    tabBar->invalidate();
}

void TabBarElement::addTab(string *id, string *name, string *uri) {
    Tab *tab = new Tab(this, id, name, uri);
    this->tabs->push_back(tab);
    if (this->tabs->size() == 1) {
        this->activeTab = tab;
    }
}

TabBarEventArgs::TabBarEventArgs(Tab *tab) {
    this->tab = tab;
}

TabBarElement::TabBarElement()
 : Element()
{
    //ctor
    this->tabs = new std::vector<Tab *>;
    this->set("active_tab_fgcolor", "#ffffff");
    this->set("active_tab_bgcolor", "#474747");
    this->addEventListener(string("mousedown"), &tabbar_mousedown);

}
TabBarElement::TabBarElement(Element *parent)
 : Element(parent)
{
    this->backgroundImage = (Image *)this->skin->getImage("tabbar.background.image", "");
    //ctor
    this->tabs = new std::vector<Tab *>;
    this->set("active_tab_fgcolor", "#ffffff");
    this->set("active_tab_bgcolor", "#474747");
    this->set("bgcolor", "#666666");
    this->addEventListener(string("mousedown"), (s_event)&tabbar_mousedown);
    std::vector<Observer *> *observers = this->observers;
    int count = observers->size();
    if (count < 1)
        {
        int f = 0;
    }


}
void TabBarElement::mousedown(int mouseButton, int x, int y) {
    TabBarElement *tabBar = this;
    x = tabBar->getAbsoluteBounds() != NULL ? x - tabBar->getAbsoluteBounds()->x : x;
    y = tabBar->getAbsoluteBounds() != NULL ? y - tabBar->getAbsoluteBounds()->y : y;
    FontStyle *font = (FontStyle *)tabBar->getFont();
    int left = 0;
    for(std::vector<Tab *>::iterator it = tabBar->getTabs()->begin(); it != tabBar->getTabs()->end(); ++it) {
        Tab *tab = (Tab *)static_cast<Tab *>(*it);
        string *title = tab->getName();
        string *id = tab->getId();
        string *uri = tab->getUri();
        GraphicsContext *g = tabBar->createGraphics();
        rectangle strSize = g->measureString((char *)title->c_str(), font);
        int width = 100;//20 + strSize.width + 20;
        if (x > left  && x < left + width) {
            tabBar->activeTab = tab;
            TabBarEventArgs *args = new TabBarEventArgs(tab);
            tabBar->notify(string("tabselected"), (SPType *)tabBar, (EventArgs *)args);
        cout << title->c_str();
            break;
        }

        left += width;
    }
    tabBar->invalidate();
}
#define SPOTIFY2009 true
void TabBarElement::draw(int x, int y, GraphicsContext *g) {
    Element::draw(x, y, g);
    if (this->absoluteBounds == NULL)
        this->absoluteBounds = new rectangle;

    this->absoluteBounds->x = x;
    this->absoluteBounds->y = y;
    this->absoluteBounds->width = this->getWidth();
    this->absoluteBounds->height = this->getHeight();
    g->fillRectangle(x, y, this->getWidth(), this->getHeight(), (Color *)this->getAttributeObj("bgcolor"));
    int left = 0;
    std::vector<Tab *>::iterator it = this->getTabs()->begin();
    do {
        Color *fgColor = (Color *)this->getAttributeObj("fgcolor");

        Tab *tab = (Tab *)static_cast<Tab *>(*it);

        string *title = tab->getName();
        string *id = tab->getId();
        rectangle strSize = g->measureString((char *)title->c_str(), font);
        int width = 100;// 20 + strSize.width + 20;
        if (this->activeTab == tab) {
            #if SPOTIFY2009
            fgColor = (Color *)this->getAttributeObj("active_tab_fgcolor");
            Color *bgColor = (Color *)this->getAttributeObj("active_tab_bgcolor");
            g->fillRectangle(x + left, y, width, this->getHeight(), bgColor);
            #else
            Color *bgColor = (Color *)this->getAttributeObj("highlight");
            g->fillRectangle(x + left, y + this->getHeight() - 5, width, 5, bgColor);
            #endif
        } else {
            #if SPOTIFY2009
            // Draw line
            g->drawLine(left + width, y, left + width, this->getHeight() + y, new Color(0, 0, 0, 1));
            #endif
        }
        g->drawString((char *)title->c_str(), font, fgColor, left + x + 20, y + (this->getHeight() / 2) - (strSize.height / 2), strSize.width, strSize.height);
        left += width;
        ++it;
    } while (it != this->getTabs()->end());
}


TabBarElement::~TabBarElement()
{
    //dtor
}
}
