#include "ButtonElement.h"

spider::ButtonElement::ButtonElement()
: spider::Element() {

	this->set("bgcolor", new string("#111111"));
	this->set("fgcolor", new string("#ffffff"));
}
void spider::ButtonElement::draw(int x, int y, spider::GraphicsContext *c)
{
    if (this->absoluteBounds == NULL)
    this->absoluteBounds = new rectangle;

    this->absoluteBounds->x = x + this->getX();
    this->absoluteBounds->y = y + this->getY();
    this->absoluteBounds->width = this->getWidth();
    this->absoluteBounds->height = this->getHeight();

    Color *bgColor = (Color *)this->getAttributeObj("bgcolor");
    Color *fgColor = (Color *)this->getAttributeObj("fgcolor");
    int fontSize = (int)this->getAttributeObj("size");
    string *fontFamily = (string *)this->getAttributeObj("font");
    if (fontFamily == NULL) {
        fontFamily = new string("MS Sans Serif");
    }
	c->fillRectangle(this->absoluteBounds->x, this->absoluteBounds->y, width, height, bgColor);

    if(this->getInnerText() != NULL) {
        spider::FontStyle *font = new FontStyle((char *)fontFamily->c_str(), fontSize, false, false, false);
		char *text = this->getInnerText();
		spider::rectangle tSize = c->measureString(text, font);
		int x = (this->getWidth() / 2) - (tSize.width / 2) + this->absoluteBounds->x;
		int y = (this->getHeight() / 2) - (tSize.height / 2) + this->absoluteBounds->y;

		c->drawString(text,font, fgColor, x, y, this->getWidth(), tSize.height);
		delete font;
	}
}
