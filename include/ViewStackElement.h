#ifndef VIEWSTACKELEMENT_H
#define VIEWSTACKELEMENT_H
#include "BoxElement.h"
#include "ViewElement.h"
#include <stack>
namespace spider {
    class ViewStackElement : public BoxElement {
    private:
        std::stack<string *> *history;
        std::stack<string *> *future;
        ViewElement *activeView;

    public:
        ViewStackElement();
        ViewStackElement(Element *parent);
        void registerView(ViewElement *view);
        void navigate(string uri);
    };
}
#endif // VIEWSTACKELEMENT_H
