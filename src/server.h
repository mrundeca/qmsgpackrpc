#ifndef SERVER_H
#define SERVER_H

#include "service.h"
#include "servicesocket.h"

namespace MsgPackRpc {

class Server
{
public:
    Server();
    virtual ~Server();

    void serve(Service *service);

protected:
    Service *service_;
    QList<ServiceSocket *> clients_;
};

} // namespace MsgPackRpc

#endif // SERVER_H
