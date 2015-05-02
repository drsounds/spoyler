#ifndef RESPONSE_H
#define RESPONSE_H
#include <string>
using namespace std;

namespace spider {
class Response
{
    public:
        Response();
        virtual ~Response();

        string content_type;
        int status;


    protected:
    private:
};
}
#endif // RESPONSE_H
