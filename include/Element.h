#ifndef ELEMENT_H
#define ELEMENT_H
#include "Node.h"
#include "Observable.h"
#include "FontStyle.h"
#include "MouseEventArgs.h"
#include "GraphicsContext.h"
#include "Stylesheet.h"
#include "Skin.h"
#include <vector>
namespace spider {
    class Skin;
    class GraphicsContext;

    class Element : public Node, public Observable {


    public:
        Skin *skin;
        Image *backgroundImage;
        vector<string> *classList;
        void applyColorAttributeFromSkin (string attr, string skin);
        void applyImageAttributeFromSkin (string attr, string skin);
        bool hasClass(string _class);
        void addClass(string _class);
        void removeClass(string _class);
        void setObject(string key, void *object);
        void setObject(const std::string& title, void *object);
        rectangle *absoluteBounds;
        void applyStylesheet(Stylesheet *style);
        int width;
        int height;
        int x;
        int y;
        int z;
        int scrollX;
        int scrollY;
        string name;


        void setName(string name) {
            this->name = name;
         }
        string getName() {
            return name;
        }

        bool scrollable;
        bool visible;
        margin *margins;
        margin *padding;
        std::vector<Observer *> *observers;
        FontStyle *font;
        char *id;
        char *data;
        Element *windowElement;
        Element *mainWindowElement;
        virtual void draw(int x, int y, GraphicsContext *c);
        virtual string getType() {
            return "element";
        }
        rectangle *getAbsoluteBounds() {
            return this->absoluteBounds;
        }
        void invalidate();
        void setAbsoluteBounds(rectangle *absoluteBounds) {
            this->absoluteBounds = absoluteBounds;
        }
        Element *getMainWindowElement() {
            return this->mainWindowElement;
        }
        void setMainWindowElement(Element* mainWindowElement) {
            this->mainWindowElement = mainWindowElement;
        }
        bool isVisible() {
            return this->visible;
        }
        Element *getWindowElement() {
             return this->windowElement;
        }
        virtual GraphicsContext *createGraphics();
        void setWindowElement(Element *windowElement) {
            this->windowElement = windowElement;
        }
        virtual void setVisible(bool visible) {
            this->visible = visible;

           // ((Element *)this->getParent())->pack();
        }
        void show();
        void hide();
        bool isScrollable() {
            return this->scrollable;
        }
        void setScrollable(bool scrollable) {
            this->scrollable = scrollable;
        }
        int getScrollX() {
            return this->scrollX;
        }
        int getScrollY() {
            return this->scrollY;
        }
        void setScrollX(int x) {
            this->scrollX = x;
        }
        void setScrollY(int y) {
            this->scrollY = y;
        }
        FontStyle *getFont();
        void setFont(FontStyle *font)  {
            this->font = font;
        }
        Element();
        Element(Element *parent);
        ~Element();
        int getX();
        margin *getMargins();
        margin *getPadding();
        char *getInnerText();
        void setInnerText(char *data);
        virtual void mouseMove(int& x, int& y) {}
        virtual void mouseClick(int& mouseButton, int& x, int& y);
        virtual void mouseDown(int& mouseButton, int& x, int& y);
        virtual void click(int mouseButton, int x, int y);
        virtual void mousedown(int mouseButton, int x, int y);
        virtual void mouseup(int mouseButton, int x, int y);
        int getY();
        int getWidth();
        int getHeight();
        int getZ();
        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setZ(int z);
        void set(const std::string& title, const std::string val);
        void set(const std::string& title, std::string *val);


        char *getId();
        void setId(char *id);
        virtual void pack() {}

    };
}
#endif // ELEMENT_H
