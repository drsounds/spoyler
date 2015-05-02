#include "Request.h"
namespace spider {
Request::Request()
{
    if (spider::handlers == NULL) {
        spider::handlers = new std::vector<IRequestHandler *>;
    }
    //ctor
}
IRequestHandler *Request::getMatchingHandlerForUri(string uri) {
    for (std::vector<IRequestHandler *>::iterator it = spider::handlers->begin(); it != spider::handlers->end(); ++it) {
        IRequestHandler *handler = (IRequestHandler *)*it;
        if (handler->handlesUri(uri)) {
            return handler;
        }
    }
}
Response *Request::request(string method, string uri, std::map<string, string> *headers, void *data) {
    IRequestHandler *handler = this->getMatchingHandlerForUri(uri);
    Response *response = handler->processRequest(method, uri, headers, data);
    return response;
}
Request::~Request()
{
    //dtor
}
}
