#ifndef REQUEST_H
#define REQUEST_H
#include <map>
#include <vector>
#include "IRequestHandler.h"
namespace spider {
static vector<IRequestHandler *> *handlers;
class Request
{
    public:
        Request();
        virtual ~Request();

        IRequestHandler *getMatchingHandlerForUri(string uri);

        string method;
        string uri;
        std::map<string, string> *headers;
        void *data;
        int status;
        Response *request(string method, string uri, std::map<string, string> *headers, void *data);

        Response *response;

        void requestAsync(string method, string uri, std::map<string, string> *headers, void *data);

    protected:
    private:
};
}

#endif // REQUEST_H
