#ifndef WHATSNEWVIEW_H
#define WHATSNEWVIEW_H
#include "ContainerViewElement.h"
#include "DOMViewElement.h"
namespace spider {
    namespace views {
        class WhatsNewView : public ContainerViewElement
        {
            public:
                WhatsNewView();
                WhatsNewView(Element *parent);
                virtual ~WhatsNewView();
                void navigate(string uri);
                bool acceptsUri(string uri);
            protected:
            private:
        };
    }
}

#endif // WHATSNEWVIEW_H
