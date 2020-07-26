#include "tcpserver.h"

using MsgPackRpc::TcpServer;

TcpServer::TcpServer(QObject *parent)
    : QTcpServer(parent)
{
}
