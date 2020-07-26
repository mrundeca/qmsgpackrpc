#include "servicesocket.h"

using MsgPackRpc::ServiceSocket;

ServiceSocket::ServiceSocket(MsgPackRpc::Service *service, QIODevice *device, QObject *parent)
    : AbstractSocket(device, parent),
      service_(service)
{
}

void ServiceSocket::processRequest(const Request &request)
{
    service_->dispatch(request);
}

void ServiceSocket::processNotification(const Notification &notification)
{
    service_->dispatch(notification);
}
