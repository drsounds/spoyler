#ifndef USERVIEW_H
#define USERVIEW_H
#include "TabbarViewElement.h"
#include "DOMViewElement.h"
#include "TextElement.h"
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
                TextElement *text;
            private:
        };
    }
}
#endif // USERVIEW_H
