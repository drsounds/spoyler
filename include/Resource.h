#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
using namespace std;
namespace spider {
class Resource
{
    public:
        Resource(string *uri);
        virtual ~Resource();
        string *getName() {
            return this->name;
        }
    protected:
        string *uri;
        string *name;
        Resource *author;
        Resource *collection;
        Resource *playlist;

    private:
};
}
#endif // RESOURCE_H
