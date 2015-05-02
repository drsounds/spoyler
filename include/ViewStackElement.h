#ifndef VIEWSTACKELEMENT_H
#define VIEWSTACKELEMENT_H
#include "BoxElement.h"
#include "ViewElement.h"
#include <stack>
namespace spider {
    class ViewStackElement : public VBoxElement {
    private:
        std::stack<string *> *history;
        std::stack<string *> *future;
        ViewElement *activeView;

    public:
        virtual void pack();
        virtual string getType() {
            return "viewstack";
        }
        ViewStackElement();
        ViewStackElement(Element *parent);
        void registerView(ViewElement *view);
        void navigate(string uri);
        virtual void appendChild(Node *child);
    };
}
#endif // VIEWSTACKELEMENT_H
