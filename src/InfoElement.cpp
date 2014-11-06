#include "InfoElement.h"
#include "ButtonElement.h"
#include "TextElement.h"
#include <list>
namespace spider {
    InfoElement::InfoElement(Element *parent)
     : HBoxElement(parent)
    {
        //ctor
        this->set("height", "32");
        this->getPadding()->top = 5;
        this->getPadding()->left = 5;
        this->getPadding()->right = 5;
        this->getPadding()->bottom = 5;

        TextElement *icon = new TextElement(this);
        icon->set("width", "128");
        this->appendChild(icon);
        this->textElement = new TextElement(this);
        this->textElement->set("flex", "1");
        this->appendChild(this->textElement);

        this->btnElement = new ButtonElement(this);
        this->btnElement->set("width", "64");
        this->btnElement->setInnerText("X");
        this->appendChild(this->btnElement);

    }
    void InfoElement::show(MessageType type, char *text) {
        this->setMessageType(type);
        this->textElement->setInnerText(text);
        Element::show();
        this->mainWindowElement->pack();

    }
    void InfoElement::hide() {
        Element::hide();
        this->mainWindowElement->pack();
    }
    void InfoElement::setMessageType(MessageType type) {
        this->type = type;
        string bgcolor = "#ffffaa";
        switch(type) {
        case Warning:
            bgcolor = "#ffffaa";
            break;
        case Info:
            bgcolor = "#00ffff";
            break;
        case Error:
            bgcolor = "#ffeeee";
            break;
        case Message:
            bgcolor = "#eeffee";
            break;
        }
        this->set("bgcolor", bgcolor);

        for (std::vector<Node *>::iterator it = this->children->begin(); it != this->children->end(); ++it) {
            Node *node = dynamic_cast<Node *>(*it);
            node->set("bgcolor", bgcolor);

        }

    }
    InfoElement::~InfoElement()
    {
        //dtor
    }
}
