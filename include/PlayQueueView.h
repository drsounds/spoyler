#ifndef PLAYQUEUEVIEW_H
#define PLAYQUEUEVIEW_H
#include "Element.h"
#include "ViewElement.h"
#include "ContainerViewElement.h"
namespace spider {
    namespace views {
        class PlayQueueView : public ContainerViewElement
        {
            public:
                PlayQueueView();
                PlayQueueView(Element *parent);
                void navigate(string uri);
                bool acceptsUri(string uri);
                virtual ~PlayQueueView();
                string getType();
            protected:
            private:
        };
    }
}


#endif // PLAYQUEUEVIEW_H
