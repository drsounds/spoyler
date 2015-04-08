#include "TopListView.h"
#include "HBoxElement.h"
#include "TableElement.h"
#include "MockTableDataSource.h"
#include "VBoxElement.h"
#include <regex>
namespace spider {
    namespace views {
        TopListView::TopListView() :
            ContainerViewElement::ContainerViewElement() {
        }
        string TopListView::getType() {
            return "toplistview";
        }
        TopListView::TopListView(Element *parent)
            : ContainerViewElement::ContainerViewElement(parent)
        {

            this->clipView = true;
             // Build the view
            // Build the view
            HBoxElement *hbox = new HBoxElement(this);
            hbox->getPadding()->top = 12;
            hbox->getPadding()->left = 16;
            hbox->getPadding()->bottom = 12;
            hbox->getPadding()->right =  16;



            hbox->set("height", "60");

            this->appendChild(hbox);

            // Add Header
            HBoxElement *title = new HBoxElement(hbox);
            title->set("fgcolor", "#aaffaa");
            title->setInnerText("What's New\0");
            title->set("height", "60");
            title->set("width", "120");
            title->set("size", "16");
            hbox->appendChild(title);
            TableElement *tableView = new TableElement(this, new MockTableDataSource());
            this->appendChild(tableView);
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
