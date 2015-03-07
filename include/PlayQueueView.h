#ifndef PLAYQUEUEVIEW_H
#define PLAYQUEUEVIEW_H
#include "Element.h"
#include "ViewElement.h"
namespace spider {
    namespace views {
        class PlayQueueView : public ViewElement
        {
            public:
                PlayQueueView();
                PlayQueueView(Element *parent);
                void navigate(string uri);
                bool acceptsUri(string uri);
                virtual ~PlayQueueView();
                virtual string getType() {
                    return "playqueue";
                }
            protected:
            private:
        };
    }
}


#endif // PLAYQUEUEVIEW_H
