#ifndef STYLESHEET_H
#define STYLESHEET_H
#include "Node.h"
namespace spider {
class Selector : Node {
public:
    Selector();
    virtual ~Selector();
};
class Stylesheet
{
    public:
        Stylesheet();
        virtual ~Stylesheet();
    protected:
        map<string, Selector *> *selectors;
    private:
};
}

#endif // STYLESHEET_H
