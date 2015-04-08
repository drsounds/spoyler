#include "Element.h"
#include <iostream>
#include <cstdio>
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
void Element::addClass(string value) {
    this->classList->push_back(value);
}

bool Element::hasClass(string value) {
   return  std::find(this->classList->begin(), this->classList->end(), value) != this->classList->end();
}

void Element::removeClass(string value) {
    this->classList->erase(std::find(this->classList->begin(), this->classList->end(), value), this->classList->end());
}

Element::Element() :
    Node() {
    this->classList = new vector<string>;
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

void Element::applyColorAttributeFromSkin (string attr, string prop) {
    if (this->skin == NULL) {
        this->skin = new Skin("skin.png", NULL);
    }
    cout << prop << "\r\n";
    cout << this->skin->colors << "\r\n";
    cout << attr << "\r\n";
    if (this->skin->colors->find(prop) != this->skin->colors->end()) {
        pixel *color = (*this->skin->colors)[prop];

        this->set(attr, spider_pixel_to_hex(color));
    }
}

void Element::applyImageAttributeFromSkin (string attr, string prop) {
    if (this->skin == NULL) {
        this->skin = new Skin("skin.png", NULL);
    }
    cout << attr << "\r\n";
    cout << skin << "\r\n";
    cout << this->skin->colors << "\r\n";
    cout << attr << "\r\n";
    if (this->skin->images->find(prop) != this->skin->images->end()) {
        Image *img = (*this->skin->images)[prop];

        this->setObject(attr, (void *)img);
    }
}


Element::Element(Element *parent) :
    Node() {
    this->classList = new vector<string>;
    this->absoluteBounds = NULL;
	this->setScrollable(false);

	this->visible = true;
	this->scrollX = 0;
	this->scrollY = 0;
    this->data = NULL;
	this->observers = new vector<Observer *>();
	this->setParent(parent);
	this->skin = ((Element *)this->parent)->skin;


    #if false
    this->set("fgcolor", new string("#ffffff"));
    this->set("bgcolor", new string("#000000"));
    this->set("font", new string("MS Sans Serif"));
    this->set("highlight", "#a9d9fe");
    this->set("size", new string("11"));
    #endif

    this->applyColorAttributeFromSkin(string("bgcolor"), string("body.background.color"));
    this->applyColorAttributeFromSkin(string("fgcolor"), string("body.foreground.color"));

    string type = string(this->getType());

    this->applyColorAttributeFromSkin(string("bgcolor"), string(this->getType()) + "body.background.color");
    this->applyColorAttributeFromSkin(string("fgcolor"), string(this->getType()) + "body.foreground.color");
    if (this->skin->hasImage(string(this->getType()) + ".background.image")) {
        this->backgroundImage = this->skin->getImage(string(this->getType()) + ".background.image", "");
    }
	if (this->getParent() != NULL) {
        #if false
        this->set("bgcolor", new string(this->getParent()->get("bgcolor")));
        this->set("fgcolor", new string(this->getParent()->get("fgcolor")));
        this->set("font", new string(this->getParent()->get("font")));
        this->set("highlight", new string(this->getParent()->get("highlight")));
        this->set("size", new string(this->getParent()->get("size")));
        #endif
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


void Element::setObject(const std::string& title, void *object) {
    (*this->getProperties())[title] = (void *)object;
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


string Element::getType() {
    return "element";
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
	if (this->clipView) {
        c->setClip(*absoluteBounds);
	}
    Color *bgColor = (Color *)this->getAttributeObj("bgcolor");
    Color *fgColor = (Color *)this->getAttributeObj("fgcolor");
    int fontSize = (int)this->getAttributeObj("size");
    string *fontFamily = (string *)this->getAttributeObj("font");
    if (fontFamily == NULL) {
        fontFamily = new string("MS Sans Serif");
    }
    c->fillRectangle(x, y, width, height, bgColor);
    string sel = "";
    sel.append(this->getType());
    sel.append(".background.image");
    c->skin->drawImageSlice(sel, c, x, y, width, height);

    // Draw background image
    if (this->getId() != NULL && strlen(this->getId()) > 0) {
        string sel2 = "#";
        sel2.append(this->getId());
        sel2.append(".background.image");
        c->skin->drawImageSlice(sel2, c, x, y, width, height);
       // c->drawImage(this->backgroundImage,  x - scrollX, y - scrollY, width, height);
    }
	//c->drawRectangle(x, y, this->getWidth(), this->getHeight(), (Color *)this->getAttributeObj("bgcolor"));
	//Color color(255, 0, 0, 255);
    //	c->drawRectangle(0, 0, this->getWidth(), this->getHeight() , &color);
    char *text = this->getInnerText();
    // draw text
    if (text != NULL)
        c->drawString(this->getInnerText(), new FontStyle((char *)fontFamily->c_str(), fontSize, fontSize / 2, false, false), fgColor, x - scrollX, y - scrollY, this->getWidth(), this->getHeight());

	// adjust for scroll
    x -= this->scrollX;
    y -= this->scrollY;
	for(std::vector<Node *>::iterator it = children->begin(); it != children->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);
		if(elm != NULL) {
			elm->draw(x + this->getPadding()->left - scrollX, y  + this->getPadding()->top - scrollY, c);
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
	if (clipView) {
        c->declipRect();
	}
}

void Element::scroll(int scrollX, int scrollY, int x, int y) {

    int xx = this->getAbsoluteBounds() != NULL ? x - this->getAbsoluteBounds()->y : x;
    int yy = this->getAbsoluteBounds() != NULL ? y - this->getAbsoluteBounds()->y : y;

    bool foundElement = false;
	for(vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);
		string ttype = elm->getType();
		char *type = (char *)ttype.c_str();
		cout << type << endl;
        if (elm->isVisible()) {
            if (elm->getAbsoluteBounds() != NULL) {

                if(x > elm->getAbsoluteBounds()->x && x < elm->getAbsoluteBounds()->x + elm->getAbsoluteBounds()->width &&
                    y > elm->getAbsoluteBounds()->y && y < elm->getAbsoluteBounds()->y + elm->getAbsoluteBounds()->height ) {
                    foundElement = true;
                    if (elm->clipView) {
                        elm->scroll(scrollX, scrollY);
                    } else {
                        elm->scroll(scrollX, scrollY, x, y);
                    }

                }
                else {

                }
            } else {
            }
        }

	}
	if (!foundElement) {
        if (this->clipView) {
            this->scroll(scrollX, scrollY);
        }
	}

}

void Element::scroll(int x, int y) {
    if (this->clipView) {
        this->scrollX += x;
        this->scrollY += y;
        if (scrollY < 0) {
            scrollY = 0;
        }
        this->invalidate();
    }
}

void Element::scrollTo(int x, int y) {
    if (this->clipView) {
        this->scrollX = x;
        this->scrollY = y;

        if (scrollY < 0) {
            scrollY = 0;
        }
        this->invalidate();

    }

}

char *Element::getInnerText() {
    char *data = this->data;
	return data;
}
void Element::setInnerText(char *data) {
	 this->data = data;
}
}


