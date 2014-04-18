#ifndef STYLESHEET_H
#define STYLESHEET_H
#include "Node.h"
namespace spider {
class Stylesheet
{
    public:
        Stylesheet();
        virtual ~Stylesheet();
    protected:
        map<string, Selector *> *selectors;
    private:
};
class Selector : Node {

};
}

#endif // STYLESHEET_H
