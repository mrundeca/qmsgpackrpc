#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <QList>
#include <QTcpServer>
#include "abstractserver.h"
#include "service.h"
#include "servicesocket.h"

namespace MsgPackRpc {

class TcpServer : public QTcpServer, public AbstractServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);
    ~TcpServer() override;

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onClientDisconnected();
};

} // namespace MsgPackRpc

#endif // TCPSERVER_H
