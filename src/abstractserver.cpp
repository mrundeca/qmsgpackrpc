#include "abstractserver.h"

using MsgPackRpc::AbstractServer;

AbstractServer::AbstractServer()
{
}

AbstractServer::~AbstractServer()
{
    foreach (ServiceSocket *client, clients_) {
        client->deleteLater();
    }
    clients_.clear();
}

void AbstractServer::serve(Service *service)
{
    service_ = service;
}
