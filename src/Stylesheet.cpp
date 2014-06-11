#include "Stylesheet.h"
namespace spider {

Selector::Selector()
 : Node() {
 }
Selector::~Selector() {

}

Stylesheet::Stylesheet()

{

    this->selectors = new map<string, Selector *>;
    //ctor
}

Stylesheet::~Stylesheet()
{
    //dtor
}
}
