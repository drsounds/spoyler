#include "TopListView.h"
#include "HBoxElement.h"
#include "TableViewElement.h"
#include "MockTableViewDataSource.h"
#include "VBoxElement.h"
#include <regex>
namespace spider {
    namespace views {
        TopListView::TopListView() :
            ContainerViewElement::ContainerViewElement() {
        }
        TopListView::TopListView(Element *parent)
            : ContainerViewElement::ContainerViewElement(parent)
        {

            this->clipView = true;
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

            TableViewElement *tableView = new TableViewElement(this, new MockTableViewDataSource());
            this->appendChild(tableView);
            tableView->setHeight(100);

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
