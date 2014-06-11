#ifndef SERVER_H
#define SERVER_H

namespace spider {
   typedef void (*spider_server_reply)(int code, char *data);
class Server
{
    public:
        Server();
        virtual ~Server();
        void request(char *method, char *uri, void *data, spider_server_reply *reply);
    protected:
    private:
};
}
#endif // SERVER_H
