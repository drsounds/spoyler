#include "DoctrineView.h"
#include "TextElement.h"
#include <regex>
#include <string>
#include <vector>
namespace spider {
    namespace views {
        DoctrineView::DoctrineView(Element *parent)
         : ContainerViewElement(parent)
        {
            this->getPadding()->top = 20;
            this->getPadding()->left = 20;
            //ctor
            text = new TextElement(this);
            text->setInnerText("Doctrine");
            text->set("height", "160");
            text->set("fgcolor", "#99CC00");
            text->set("size", "25");
            text->set("width", "100%");
            this->appendChild(text);
        }

        bool DoctrineView::acceptsUri(string uri) {
            char *uri2 = (char *)uri.c_str();
            bool a = std::regex_match(uri2, std::regex("spotify:doctrine:(.*)"));
            return a;
        }

        void DoctrineView::navigate(string uri) {

           /* std::vector<std::string> strs;
            boost::split(strs, uri, boost::is_any_of(":"));
            string id = strs.at(2);
            char *buffer = new char[50];
            int length = id.copy(buffer, id.size(), 0);
            buffer[length] = '\0';*/
            this->text->setInnerText("");
        }

        DoctrineView::~DoctrineView()
        {
            //dtor
        }
    }
}
