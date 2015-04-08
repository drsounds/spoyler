#ifndef TOPLISTVIEW_H
#define TOPLISTVIEW_H
#include "Element.h"
#include "ContainerViewElement.h"
namespace spider {
    namespace views {
        class TopListView : public ContainerViewElement
        {
            public:
                TopListView();
                TopListView(Element *parent);
                virtual ~TopListView();
                bool acceptsUri(string uri);
                void navigate(string uri);
                string getType() {
                    return "toplistview";
                }
            protected:
            private:
        };
    }
}

#endif // TOPLISTVIEW_H
