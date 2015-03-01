#include "PlayQueueView.h"
#include <regex>
namespace spider {
    namespace views {
        PlayQueueView::PlayQueueView()
         : ViewElement()
        {
            //ctor
        }
        PlayQueueView::PlayQueueView(Element *parent)
            : ViewElement(parent)
        {
            //ctor
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
