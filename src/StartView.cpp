#include "StartView.h"
#include <regex>
#include "WhatsNewView.h"
#include "TopListView.h"
namespace spider {
    namespace views {
        StartView::StartView() : TabbarViewElement() {
        }
        StartView::StartView(Element *parent)
         : TabbarViewElement(parent)
        {
            this->clipView = false;
            //ctor
            this->viewStack->appendChild(new views::WhatsNewView(this->viewStack));
            this->viewStack->appendChild(new views::TopListView(this->viewStack));
            this->tabBar->addTab(new string ("Overview"), new string("overview"), new string("spotify:internal:start"));
            this->tabBar->addTab(new string ("Top List"), new string("toplist"), new string("spotify:internal:toplist"));
        }

        bool StartView::acceptsUri(string uri) {
            return std::regex_match(uri.c_str(), std::regex("spotify:internal:(start|toplist)"));
        }

        StartView::~StartView()
        {
            //dtor
        }
    }
}
