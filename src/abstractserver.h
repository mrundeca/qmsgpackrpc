#ifndef ABSTRACTSERVER_H
#define ABSTRACTSERVER_H

#include "service.h"

namespace MsgPackRpc {

class AbstractServer
{
public:
    AbstractServer();
    void serve(Service *service);
};

} // namespace MsgPackRpc

#endif // ABSTRACTSERVER_H
