#ifndef TITLEELEMENT_H
#define TITLEELEMENT_H
#include "VBoxElement.h"
#include "TextElement.h"
namespace spider {
class TitleElement : public VBoxElement
{
    public:
        TitleElement();
        TitleElement(Element *parent);
        virtual ~TitleElement();
        string getTitle();
        void setTitle(string);
        string getEntity();
        void setEntity(string);
        virtual string getType() {
            return "title";
        }
    protected:
        TextElement *title;
        TextElement *entity;
    private:
};
}
#endif // TITLEELEMENT_H
