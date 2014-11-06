#ifndef DOCTRINEVIEW_H
#define DOCTRINEVIEW_H
#include "ViewElement.h"
#include "TextElement.h"
namespace spider {
    namespace views {
class DoctrineView : public ViewElement
{

    public:

        DoctrineView(Element *parent);
        virtual ~DoctrineView();
        void navigate(string uri);
        bool acceptsUri(string uri);
    protected:
        TextElement *text;
    private:
};
    }
}
#endif // DOCTRINEVIEW_H
