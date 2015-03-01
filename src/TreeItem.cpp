#include "TreeItem.h"
#include <regex>
namespace spider {
    TreeItem::TreeItem(Uri *uri) {
        this->highlighted = false;
        this->uri = uri;
        this->setText("Loading...");
        if (std::regex_match(uri->uri, std::regex("spotify:internal:start"))) {
            this->setText("Start");
        }
    }
}
