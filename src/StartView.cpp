#include "StartView.h"
#include <regex>
#include "WhatsNewView.h"
namespace spider {
    namespace views {
        StartView::StartView() : TabbarViewElement() {
        }
        StartView::StartView(Element *parent)
         : TabbarViewElement(parent)
        {
            //ctor
            this->viewStack->appendChild(new views::WhatsNewView(this->viewStack));
            this->tabBar->addTab(new string ("Overview"), new string("overview"), new string("spoyler:internal:start"));
            this->tabBar->addTab(new string ("Top List"), new string("toplist"), new string("spoyler:internal:toplist"));
        }

        bool StartView::acceptsUri(string uri) {
            return std::regex_match(uri.c_str(), std::regex("spoyler:internal:(start|toplist)"));
        }

        StartView::~StartView()
        {
            //dtor
        }
    }
}
