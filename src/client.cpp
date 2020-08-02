#include "client.h"
#include <QtDebug>

using MsgPackRpc::Client;
using MsgPackRpc::Request;

Client::Client(QIODevice *device, QObject *parent)
    : AbstractSocket (device, parent)
{
}

void Client::processRequest(const Request &request)
{
    // client shouldn't process request
    qDebug() << "Ignoring request " << request.method();
}

void Client::processNotification(const Notification &notification)
{
    qDebug() << "Dispatching notification " << notification.method();
    dispatch(notification);
}

void Client::processResponse(const Response &response)
{
    qDebug() << "Dispatching response " << response.msgid();
    dispatch(response);
}
