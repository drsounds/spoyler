#include "Element.h"
#include "WindowElement.h"
#include "Observable.h"
namespace spider {

void Element::mouseDown(int& mouseButton, int& x, int& y) {

}
void Element::show() {
    this->setVisible(true);
}
void Element::hide() {
    this->setVisible(false);
}
void Element::mouseClick(int& mouseButton, int& x, int& y) {

}
GraphicsContext *Element::createGraphics() {
    return this->windowElement->createGraphics();
}
void Element::click(int mouseButton, int x, int y) {
	int xx = this->getAbsoluteBounds() != NULL ? x - this->getAbsoluteBounds()->y : x;
    int yy = this->getAbsoluteBounds() != NULL ? y - this->getAbsoluteBounds()->y : y;
	MouseEventArgs *me = new MouseEventArgs(mouseButton, xx, yy);

	this->notify(string("click"), this, me);
	for(vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);

		if (elm->getAbsoluteBounds() != NULL)
		if(x > elm->getAbsoluteBounds()->x && x < elm->getAbsoluteBounds()->x + elm->getAbsoluteBounds()->width &&
			y > elm->getAbsoluteBounds()->y && y < elm->getAbsoluteBounds()->y + elm->getAbsoluteBounds()->height) {

			elm->click(mouseButton, x , y);
		}
	}
}


void Element::mousedown(int mouseButton, int x, int y) {
	int xx = this->getAbsoluteBounds() != NULL ? x - this->getAbsoluteBounds()->y : x;
    int yy = this->getAbsoluteBounds() != NULL ? y - this->getAbsoluteBounds()->y : y;
	MouseEventArgs *me = new MouseEventArgs(mouseButton, xx, yy);

	this->notify(string("mousedown"), this, me);
	for(vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);
        if (elm->getAbsoluteBounds() != NULL)
		if(x > elm->getAbsoluteBounds()->x && x < elm->getAbsoluteBounds()->x + elm->getAbsoluteBounds()->width &&
			y > elm->getAbsoluteBounds()->y && y < elm->getAbsoluteBounds()->y + elm->getAbsoluteBounds()->height) {

			elm->mousedown(mouseButton, x, y);
		}
	}
}
void Element::mouseup(int mouseButton, int x, int y) {
	int xx = this->getAbsoluteBounds() != NULL ? x - this->getAbsoluteBounds()->y : x;
    int yy = this->getAbsoluteBounds() != NULL ? y - this->getAbsoluteBounds()->y : y;
	MouseEventArgs *me = new MouseEventArgs(mouseButton, xx, yy);

	this->notify(string("mouseup"), this, me);
	for(vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);
        if (elm->getAbsoluteBounds() != NULL)
		if(x > elm->getAbsoluteBounds()->x && x < elm->getAbsoluteBounds()->x + elm->getAbsoluteBounds()->width &&
			y > elm->getAbsoluteBounds()->y && y < elm->getAbsoluteBounds()->y + elm->getAbsoluteBounds()->height) {

			elm->mouseup(mouseButton, x, y);
		}
	}
}
Element::Element() :
    Node() {
    this->absoluteBounds = NULL;
	this->setScrollable(false);
	this->visible = true;
	this->scrollX = 0;
	this->scrollY = 0;
    this->data = NULL;
    this->visible = true;
	this->observers = new vector<Observer *>();
    this->set("fgcolor", new string("#ffffff"));
    this->set("bgcolor", new string("#000000"));
    this->set("highlight", "#a9d9fe");
    this->set("font", new string("Tahoma"));
    this->set("size", new string("11"));
	this->font = new FontStyle("MS Sans Serif", 11, 1, false, false);
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->width = 0;
	this->height = 0;
	this->margins = new margin();
	this->margins->left = 0;
	this->margins->top = 0;
	this->margins->right= 0;
	this->margins->bottom = 0;
	this->padding = new margin();
	this->padding->left = 0;
	this->padding->top = 0;
	this->padding->right= 0;
	this->padding->bottom = 0;

}
FontStyle *Element::getFont() {
    int fontSize = (int)this->getAttributeObj("size");
    string *fontFamily = (string *)this->getAttributeObj("font");
    if (fontFamily == NULL) {
        fontFamily = new string("MS Sans Serif");
    }
    return new FontStyle((char *)fontFamily->c_str(), fontSize, false, false, false);
}
void Element::applyStylesheet(Stylesheet *style) {

}
Element::Element(Element *parent) :
    Node() {
    this->absoluteBounds = NULL;
	this->setScrollable(false);

	this->visible = true;
	this->scrollX = 0;
	this->scrollY = 0;
    this->data = NULL;
	this->observers = new vector<Observer *>();
	this->setParent(parent);
    this->set("fgcolor", new string("#ffffff"));
    this->set("bgcolor", new string("#000000"));
    this->set("font", new string("MS Sans Serif"));
    this->set("highlight", "#a9d9fe");
    this->set("size", new string("11"));
	if (this->getParent() != NULL) {
        this->set("bgcolor", new string(this->getParent()->get("bgcolor")));
        this->set("fgcolor", new string(this->getParent()->get("fgcolor")));
        this->set("font", new string(this->getParent()->get("font")));
        this->set("highlight", new string(this->getParent()->get("highlight")));
        this->set("size", new string(this->getParent()->get("size")));
        this->font = parent->font;
        this->mainWindowElement = parent->getMainWindowElement();
        this->windowElement = parent->getWindowElement();
	}
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->width = 0;
	this->height = 0;
	this->margins = new margin();
	this->margins->left = 0;
	this->margins->top = 0;
	this->margins->right = 0;
	this->margins->bottom = 0;
	this->padding = new margin();
	this->padding->left = 0;
	this->padding->top = 0;
	this->padding->right = 0;
	this->padding->bottom = 0;

}
void Element::invalidate() {
    rectangle *rect = this->getAbsoluteBounds();
    if (rect == NULL)
        return;
    WindowElement *we = (WindowElement *)this->getWindowElement();
    we->invalidateRegion(*rect);
}
margin *Element::getMargins() {
	return this->margins;
}
margin *Element::getPadding() {
	return this->padding;
}
Element::~Element() {

}


int Element::getHeight() {
	return this->height;
};
int Element::getWidth() {
	return this->width;
}
int Element::getX() {
	return this->x;
}
int Element::getY() {
	return this->y;
}
int Element::getZ() {
	return this->z;
}
void Element::setWidth(int w) {
	this->width = w;
}
void Element::setHeight(int h) {
	this->height = h;

}
void Element::setX(int x) {
	this->x = x;
}
void Element::setY(int y) {
	this->y = y;
}
void Element::setZ(int z) {
	this->z = z;
}

void Element::set(const std::string& title, std::string *val) {
    int n = 0;
        (*this->getAttributes())[title] = val;
    try {
        n = atoi(val->c_str());
        if(title == "width")
            this->setWidth(n);
        if(title == "height")
            this->setHeight(n);
        if(title == "x")
            this->setX(n);
        if(title == "y")
            this->setY(n);

        (*this->getProperties())[title] = (void *)n;
    } catch (const boost::bad_lexical_cast e) {
        (*this->getProperties())[title] = (void *)val;
    }

    if(val->find("#") == 0) {
        Color *c =new Color(*val);
        (*this->getProperties())[title] = (void *)c;
    }
}
 void Element::set(const std::string& title, const std::string value) {
     this->set(title, new std::string(value));
}

void Element::setId(char *id) {
	this->id = id;
}
char *Element::getId() {
	return this->id;
}







void Element::draw(int x, int y, GraphicsContext *c) {
    if (!this->isVisible()) {
        return;
    }

	spider_position pos;
	std::vector<Node *> *children = this->getChildNodes();
	x += this->getX() ;
	y += this->getY();
	if (this->absoluteBounds == NULL)
    this->absoluteBounds = new rectangle;

    this->absoluteBounds->x = x + this->getMargins()->left;
    this->absoluteBounds->y = y + this->getMargins()->bottom;
    this->absoluteBounds->width = this->getWidth() - this->getMargins()->left + this->getMargins()->right;
    this->absoluteBounds->height = this->getHeight() - this->getMargins()->top + this->getMargins()->bottom;
	int width =  this->getWidth();
	int height = this->getHeight();

	rectangle rect2;
	rect2.x = 0;
	rect2.y = 0;
	rect2.width = width;
	rect2.height = height;
    Color *bgColor = (Color *)this->getAttributeObj("bgcolor");
    Color *fgColor = (Color *)this->getAttributeObj("fgcolor");
    int fontSize = (int)this->getAttributeObj("size");
    string *fontFamily = (string *)this->getAttributeObj("font");
    if (fontFamily == NULL) {
        fontFamily = new string("MS Sans Serif");
    }
	c->fillRectangle(x, y, width, height, bgColor);
	//c->drawRectangle(x, y, this->getWidth(), this->getHeight(), (Color *)this->getAttributeObj("bgcolor"));
	//Color color(255, 0, 0, 255);
    //	c->drawRectangle(0, 0, this->getWidth(), this->getHeight() , &color);
    char *text = this->getInnerText();
    // draw text
    if (text != NULL)
        c->drawString(this->getInnerText(), new FontStyle((char *)fontFamily->c_str(), fontSize, fontSize / 2, false, false), fgColor, x, y, this->getWidth(), this->getHeight());

	// adjust for scroll
    x -= this->scrollX;
    y -= this->scrollY;
	for(std::vector<Node *>::iterator it = children->begin(); it != children->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);
		if(elm != NULL) {
			elm->draw(x + this->getPadding()->left, y  + this->getPadding()->top, c);
		}
	}
	rectangle rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;

	x += this->scrollX;
    y += this->scrollY;
	x -= this->getX();
	y -= this->getY();
	//c->setOrigo(-x - getX(), -y - getY());
}


char *Element::getInnerText() {
    char *data = this->data;
	return data;
}
void Element::setInnerText(char *data) {
	 this->data = data;
}
}


