#include "TopListView.h"
#include "HBoxElement.h"
#include "VBoxElement.h"
#include <regex>
namespace spider {
    namespace views {
        TopListView::TopListView() :
            ViewElement::ViewElement() {
        }
        TopListView::TopListView(Element *parent)
            : ViewElement::ViewElement(parent)
        {
             // Build the view
            HBoxElement *hbox = new HBoxElement(this);
            hbox->getPadding()->top = 12;
            hbox->getPadding()->left = 16;
            hbox->getPadding()->bottom = 12;
            hbox->getPadding()->right = 16;



            hbox->set("height", "60");

            this->appendChild(hbox);

            // Add Header
            HBoxElement *title = new HBoxElement(hbox);
            title->set("fgcolor", "#aaffaa");
            title->setInnerText("Top List (Coming soon)\0");
            title->set("height", "60");
            title->set("width", "120");
            title->set("size", "16");
            hbox->appendChild(title);


        }
        void TopListView::navigate(string uri) {

        }
        bool TopListView::acceptsUri(string uri) {
            return std::regex_match(uri.c_str(), std::regex("spotify:internal:toplist"));
        }
        TopListView::~TopListView()
        {
            //dtor
        }
    }
}
