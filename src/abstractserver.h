#ifndef ABSTRACTSERVER_H
#define ABSTRACTSERVER_H

#include "service.h"
#include "servicesocket.h"

namespace MsgPackRpc {

class AbstractServer
{
public:
    AbstractServer();
    virtual ~AbstractServer();

    void serve(Service *service);

protected:
    Service *service_;
    QList<ServiceSocket *> clients_;
};

} // namespace MsgPackRpc

#endif // ABSTRACTSERVER_H
