#include "UserView.h"
#include <boost/algorithm/string.hpp>
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
            std::vector<std::string> strs;
            boost::split(strs, uri, boost::is_any_of(":"));
            string id = strs.at(2);
            char *buffer = new char[50];
            int length = id.copy(buffer, id.size(), 0);
            buffer[length] = '\0';
            this->header->title->setTitle(string(buffer));
        }
        bool UserView::acceptsUri(string uri) {
            char *uri2 = (char *)uri.c_str();
            bool a = std::regex_match(uri2, std::regex("spotify:user:(.*)"));
            return a;
        }
    }
}
