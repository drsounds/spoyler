#ifndef TOPLISTVIEW_H
#define TOPLISTVIEW_H
#include "Element.h"
#include "ViewElement.h"
namespace spider {
    namespace views {
        class TopListView : public ViewElement
        {
            public:
                TopListView();
                TopListView(Element *parent);
                virtual ~TopListView();
                bool acceptsUri(string uri);
                void navigate(string uri);
            protected:
            private:
        };
    }
}

#endif // TOPLISTVIEW_H
