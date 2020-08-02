#include "tcpserver.h"
#include <QTcpSocket>

using MsgPackRpc::TcpServer;
using MsgPackRpc::ServiceSocket;

TcpServer::TcpServer(QObject *parent)
    : QTcpServer(parent)
{
}

TcpServer::~TcpServer()
{
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *tcp_socket = new QTcpSocket;
    tcp_socket->setSocketDescriptor(socketDescriptor);
    ServiceSocket *client = new ServiceSocket(service_, tcp_socket, this);
    tcp_socket->setParent(client);
    connect(tcp_socket, &QTcpSocket::disconnected,
            client, &ServiceSocket::disconnected);
    connect(client, &ServiceSocket::disconnected,
            this, &TcpServer::onClientDisconnected);
    clients_.append(client);
    emit newConnection();
}

void TcpServer::onClientDisconnected()
{
    ServiceSocket *client = qobject_cast<ServiceSocket *>(sender());
    clients_.removeAll(client);
    client->deleteLater();
}
