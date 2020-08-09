#include "servicesocket.h"
#include <QtDebug>
#include <qmsgpack/msgpack.h>

using MsgPackRpc::ServiceSocket;
using MsgPackRpc::Response;

ServiceSocket::ServiceSocket(MsgPackRpc::Service *service, QIODevice *device, QObject *parent)
    : AbstractSocket(device, parent),
      service_(service)
{
}

void ServiceSocket::processMessage(const QByteArray &message)
{
    QVariantList message_content = MsgPack::unpack(message).toList();
    if (message_content.size() < 3) {
        qWarning() << QString("Received invalid message: size %1").
                      arg(message_content.size());
        return;
    }

    switch (message_content.at(0).toInt()) {
    case kRequest:
    {
        Request request(message_content);
        processRequest(request);
        break;
    }

    case kNotification:
    {
        Notification notification(message_content);
        processNotification(notification);
        break;
    }

    case kResponse:
    {
        qDebug() << QString("Ignoring response %1").
                    arg(message_content.at(1).toInt());
        break;
    }

    default:
        break;
    }
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
