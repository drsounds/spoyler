#ifndef USERVIEW_H
#define USERVIEW_H
#include "TabbarViewElement.h"
#include "DOMViewElement.h"
#include "HeaderElement.h"
namespace spider {
    namespace views {
        class UserView : public ViewElement
        {
            public:
                UserView();
                UserView(Element *parent);
                virtual ~UserView();
                bool acceptsUri(string uri);
                void navigate(string uri);
            protected:
                HeaderElement *header;
            private:
        };
    }
}
#endif // USERVIEW_H
