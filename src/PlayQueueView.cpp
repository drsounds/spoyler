#include "PlayQueueView.h"
#include "HeaderElement.h"
#include "TableViewElement.h"
#include "MockTableViewDataSource.h"
#include <regex>
namespace spider {
    namespace views {
        PlayQueueView::PlayQueueView()
         : ContainerViewElement()
        {
            //ctor
        }
        PlayQueueView::PlayQueueView(Element *parent)
            : ContainerViewElement(parent)
        {
            this->clipView = true;
            //ctor
            HeaderElement *headerElement = new HeaderElement(this);
            headerElement->title->setTitle("Test");
            this->appendChild(headerElement);
            TableViewElement *tableView = new TableViewElement(this, new MockTableViewDataSource());
            this->appendChild(tableView);
            tableView->setHeight(100);
        }
        void PlayQueueView::navigate(string uri) {

        }
        bool PlayQueueView::acceptsUri(string uri) {
            return std::regex_match(uri.c_str(), std::regex("spotify:internal:(history|playqueue)"));
        }
        PlayQueueView::~PlayQueueView()
        {
            //dtor
        }
    }
}
