#include "client.h"
#include <QtDebug>
#include <qmsgpack/msgpack.h>

using MsgPackRpc::Client;
using MsgPackRpc::Request;
using MsgPackRpc::Response;
using MsgPackRpc::PendingCall;

Client::Client(QIODevice *device, QObject *parent)
    : AbstractSocket (device, parent),
      timeout_(-1),
      msgid_(0)
{
}

PendingCall *Client::call(const QString &method, const QVariantList &params)
{
    Request request(msgid_++, method, params);
    sendMessage(request);
    PendingCall *pending_call = new PendingCall(request, this);
    pending_calls_.append(pending_call);
    return pending_call;
}

void Client::processMessage(const QByteArray &message)
{
    QVariantList message_content = MsgPack::unpack(message).toList();
    if (message_content.size() < 3) {
        qWarning() << QString("Invalid message: size %1").
                      arg(message_content.size());
        return;
    }

    switch (message_content.at(0).toInt()) {
    case kRequest:
    {
        qDebug() << QString("Ignoring request %1").
                    arg(message_content.at(2).toString());
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
        Response response(message_content);
        processResponse(response);
        break;
    }

    default:
        break;
    }
}

void Client::processNotification(const Notification &notification)
{
    qDebug() << QString("Dispatching notification %1")
                .arg(notification.method());
    dispatch(notification);
}

void Client::processResponse(const Response &response)
{
    qDebug() << QString("Dispatching response %1")
                .arg(response.msgid());
    dispatch(response);
}

void Client::dispatch(const Response &response)
{
    foreach(PendingCall *pending_call, pending_calls_) {
        if (pending_call->request().msgid() == response.msgid()) {
            pending_call->finishRequest(response);
        }
    }
}

void Client::dispatch(const Notification &notification)
{
    qDebug() << QString("Notification not supported, ignoring %1")
                .arg(notification.method());
}
