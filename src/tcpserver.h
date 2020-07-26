#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <QTcpServer>
#include "abstractserver.h"

namespace MsgPackRpc {

class TcpServer : public QTcpServer, public AbstractServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);
};

} // namespace MsgPackRpc

#endif // TCPSERVER_H
