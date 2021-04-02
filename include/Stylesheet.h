#ifndef STYLESHEET_H
#define STYLESHEET_H
#include "Node.h"
#ifdef _MSC_VER
#endif
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
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
        string get(string entity, string prop);
    protected:
         //boost::property_tree::ptree *pt;
        map<string, string> *selectors;
    private:
};
}

#endif // STYLESHEET_H
