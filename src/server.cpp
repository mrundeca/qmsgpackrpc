#include "server.h"

using MsgPackRpc::Server;

Server::Server()
    : service_(nullptr)
{
}

Server::~Server()
{
    foreach (ServiceSocket *client, clients_) {
        client->deleteLater();
    }
    clients_.clear();
}

void Server::serve(Service *service)
{
    service_ = service;
}
