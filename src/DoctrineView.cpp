#include "DoctrineView.h"
#include "TextElement.h"
#include <regex>
namespace spider {
    namespace views {
        DoctrineView::DoctrineView(Element *parent)
        {
            //ctor
            TextElement *text = new TextElement(this);
            text->setInnerText("Doctrine");
            text->set("height", "60");
            text->set("color", "#99CC00");
            text->set("width", "100%");
            this->appendChild(text);
        }

        bool DoctrineView::acceptsUri(string uri) {
            char *uri2 = (char *)uri.c_str();
            bool a = std::regex_match(uri2, std::regex("spoyler:doctrine:(.*)"));
            return a;
        }

        void DoctrineView::navigate(string uri) {

        }

        DoctrineView::~DoctrineView()
        {
            //dtor
        }
    }
}
