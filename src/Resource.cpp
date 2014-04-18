#include "Resource.h"
namespace spider {
Resource::Resource(string *uri)
{
    //ctor
    this->uri = uri;
}

Resource::~Resource()
{
    //dtor
    delete uri;
}
}
