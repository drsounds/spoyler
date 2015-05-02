#ifndef IREQUESTHANDLER_H
#define IREQUESTHANDLER_H
#include <map>
#include <string>
#include "Response.h"
#include <map>
using namespace std;
namespace spider {
/**
 * Request handler for Spider
 */
class IRequestHandler
{
    public:
        IRequestHandler();
        virtual ~IRequestHandler();

        /**
         * Returns whether this handles this type of URI
         **/
        virtual bool handlesUri(string uri) {
            return false;
        }

        /**
         * Processes request
         **/
        virtual Response *processRequest(string method, string uri, std::map<string, string> *headers, void *payload) {
            return NULL;
        }

    protected:
    private:
};
}
#endif // IREQUESTHANDLER_H
