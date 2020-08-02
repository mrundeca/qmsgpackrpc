#include "servicesocket.h"
#include <QtDebug>

using MsgPackRpc::ServiceSocket;
using MsgPackRpc::Response;

ServiceSocket::ServiceSocket(MsgPackRpc::Service *service, QIODevice *device, QObject *parent)
    : AbstractSocket(device, parent),
      service_(service)
{
}

void ServiceSocket::processRequest(const Request &request)
{
    qDebug() << "Processing request " << request.method();
    Response response = service_->dispatch(request);
    sendMessage(response);
}

void ServiceSocket::processNotification(const Notification &notification)
{
    qDebug() << "Processing notification " << notification.method();
    service_->dispatch(notification);
}

void ServiceSocket::processResponse(const Response &response)
{
    qDebug() << "Ignoring response " << response.msgid();
    // server shouldn't process response
}
