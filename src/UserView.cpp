#include "UserView.h"
#include <string>
#include <vector>
#include <regex>
using namespace std;
namespace spider {
    namespace views {

        UserView::UserView(Element *parent)
         : ViewElement(parent)
        {
            this->getPadding()->top = 0;
            this->getPadding()->left = 0;
            //ctor
            header = new spider::HeaderElement(this);
            header->title->setTitle("Title");
            header->title->setEntity("User");
            header->set("width", "100%");
            header->set("height", "180");
            this->appendChild(header);

        }

        UserView::UserView()
        {
            //ctor
        }

        UserView::~UserView()
        {
            //dtor
        }
        void UserView::navigate(string uri) {
            this->header->title->setTitle(uri);
        }
        bool UserView::acceptsUri(string uri) {
            char *uri2 = (char *)uri.c_str();
            bool a = std::regex_match(uri2, std::regex("spotify:user:(.*)"));
            return a;
        }
    }
}
