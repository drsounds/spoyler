#ifndef SPIDERSERVER_H
#define SPIDERSERVER_H

namespace spider {
class SpiderServer
{
    public:
        SpiderServer();
        virtual ~SpiderServer();
        void request(char *method, char *uri, void *data);
    protected:
    private:
};
}

#endif // SPIDERSERVER_H
