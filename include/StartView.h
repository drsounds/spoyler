#ifndef STARTVIEW_H
#define STARTVIEW_H
#include "TabbarViewElement.h"
namespace spider {
    namespace views {
        class StartView : public TabbarViewElement
        {
            public:
                StartView();
                StartView(Element *parent);
                virtual ~StartView();
                bool acceptsUri(string uri);
                virtual string getType() {
                    return "startview";
                }
            protected:
            private:
        };
    }
}
#endif // STARTVIEW_H
