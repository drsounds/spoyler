#include "WhatsNewView.h"
#include "ButtonElement.h"
#include "HBoxElement.h"
#include "TableViewElement.h"
#include "MockTableViewDataSource.h"
#include <regex>
namespace spider {
    namespace views {
        WhatsNewView::WhatsNewView()
         : ContainerViewElement::ContainerViewElement()
        {
            this->clipView = true;
            //ctor
        }
        bool WhatsNewView::acceptsUri(string uri) {
            return std::regex_match(uri.c_str(), std::regex("spotify:internal:start"));
        }
        WhatsNewView::WhatsNewView(Element *parent)
         : ContainerViewElement::ContainerViewElement(parent)
        {


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

            // Add flex
            HBoxElement *hspacer = new HBoxElement(hbox);
            hspacer->set("flex", "1");
            hspacer->set("width", "100%");
            hspacer->set("heigh", "60");
            hbox->appendChild(hspacer);

            // Add more button
            ButtonElement *more = new ButtonElement(hbox);
            more->set("width", "150");
            more->set("height", "60");
            more->set("fgcolor", "#000000");
            more->set("bgcolor", "#878787");
            more->setInnerText("More\0");
            more->set("size", "11");
            hbox->appendChild(more);


            HBoxElement *whatsNew1 = new HBoxElement(this);
            whatsNew1->set("height", "500");
            this->appendChild(whatsNew1);

            // Create next chapter
            HBoxElement *hbox2 = new HBoxElement(this);
            hbox2->getPadding()->top = 12;
            hbox2->getPadding()->left = 16;
            hbox2->getPadding()->bottom = 12;
            hbox2->getPadding()->right =  16;
            hbox2->set("height", "200");
            this->appendChild(hbox2);

            HBoxElement *title2 = new HBoxElement(hbox);
            title2->set("fgcolor", "#ffaaff");
            title2->setInnerText("Artists you might like \0");
            title2->set("height", "60");
            title2->set("width", "620");
            title2->set("size", "16");
            hbox2->appendChild(title2);

            TableViewElement *tableView = new TableViewElement(this, new MockTableViewDataSource());
            this->appendChild(tableView);

        }
        void WhatsNewView::navigate(string uri) {

        }
        WhatsNewView::~WhatsNewView()
        {
            //dtor
        }
    }
}
