#include <string.h>
#include "DOMViewElement.h"
#include "VBoxElement.h"
#include "HBoxElement.h"
#include "ButtonElement.h"
#include "TextElement.h"
namespace spider {

    Element *p_parent;
    DOMViewElement::DOMViewElement(Element *parent) : Element(parent) {

    }
    static int offs;
    static char char_data_buffer[10024];
    static bool overflow;
    void reset_char_data_buffer (void) {
        offs = 0;
        overflow = false;
        memset(char_data_buffer, '\0', sizeof(char_data_buffer));
    }
    size_t offset = 0;
    void char_data(void *userData, const XML_Char *s, int len) {
        if (!overflow) {
            if (len + offs >= sizeof(char_data_buffer) ) {
                overflow = true;
            } else {
                memcpy(char_data_buffer + offs, s, len);
                offs += len;
            }
        }
    }
    void DOMViewElement::loadXML(char *buffer) {

        this->getChildNodes()->clear();
        this->parseDepth = 0;
        XML_Parser parser = XML_ParserCreate(NULL);
        XML_SetUserData(parser, this);
        int len = strlen(buffer);
        bool done = false;
        p_parent = this;
        XML_SetCharacterDataHandler(parser, &char_data);
        XML_SetElementHandler(parser, &startElement, &endElement);
        do {


            if (!XML_Parse(parser, buffer, len, done)) {
                break;

            }
        } while (!done);
        XML_ParserFree(parser);
        this->pack();

    }

    char *getAttribute(char *attribute, char **attributes, char *defValue) {
        if (attributes == NULL) {
            return NULL;
        }

        for (size_t i = 0; attributes[i]; i += 2) {
            const char *attr = attributes[i];
            const char *val = attributes[i+1];
            if (strcmp(attr, attribute) == 0) {
                delete attr;
                return (char *)val;
            }
        }
        return (char *)defValue;
    }

    void startElement(void *data, const char *el, const char **attr) {
        DOMViewElement *view = (DOMViewElement *)data;
        if (strcmp("document", el) == 0) {
            view->parseDepth++;
            return;
        }
        reset_char_data_buffer();
        Element *elm = NULL;
        if (strcmp(el, "document") == 0) {
            VBoxElement *vbox = new VBoxElement(p_parent);

            elm = vbox;
        }
        if (strcmp(el, "vbox") == 0) {
            VBoxElement *vbox = new VBoxElement(p_parent);

            elm = vbox;
        }
        if (strcmp(el, "hbox") == 0) {
            HBoxElement *hbox = new HBoxElement(p_parent);


            elm = hbox;
        }
        if (strcmp(el, "image") == 0) {

        }
        if (strcmp(el, "text") == 0) {
            TextElement *textElement = new TextElement(p_parent);
            elm = textElement;

        }
        if (strcmp(el, "button") == 0) {
            ButtonElement *button = new ButtonElement(p_parent);
            elm = button;
            button->set("height", "32");
            button->set("width", "120");
        }
        if (elm == NULL) {
            elm = new VBoxElement(p_parent);
        }

        // Get common attributes
        char *flex = getAttribute("flex", (char **)attr, NULL);
        if (flex != NULL) {
            if (elm != NULL) {
                elm->set(string("flex"), new string(flex));
            }
        }

        char *height = getAttribute("height", (char **)attr, NULL);
        if (height != NULL) {
            if (elm != NULL) {
                elm->set(string("height"), new string(height));
            }
        }

        char *width = getAttribute("width", (char **)attr, NULL);
        if (width != NULL) {
            if (elm != NULL) {
                elm->set(string("width"), new string(width));
            }
        }

        if (p_parent != NULL && elm != NULL)
        p_parent->appendChild(elm);
        view->parseDepth++;
        p_parent = elm;
    }

    void endElement(void *data, const char *el) {
        DOMViewElement *view = (DOMViewElement *)data;
        if (p_parent != NULL) {

            char *text = (char *)malloc(sizeof(char_data_buffer));

            memcpy(text, char_data_buffer, sizeof(char_data_buffer));
            p_parent->setInnerText(text);

            p_parent = (Element *)p_parent->getParent();

        }
        view->parseDepth--;

    }
}
