#include "Server.h"
namespace spider {
Server::Server()
{
    //ctor
}

void Server::request(char *method, char *uri, void *data, spider_server_reply *reply) {
    if (strcmp(method, "GET") == 0) {
        if (strcmp(uri, "spoyler:internal:home") == 0) {

        }
    }
}
Server::~Server()
{
    //dtor
}
