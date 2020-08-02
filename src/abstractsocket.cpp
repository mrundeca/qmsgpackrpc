#include "abstractsocket.h"
#include <QtDebug>
#include <QDataStream>
#include <qmsgpack/msgpack.h>
#include "request.h"
#include "notification.h"

using MsgPackRpc::AbstractSocket;

AbstractSocket::AbstractSocket(QIODevice *device, QObject *parent)
    : QObject(parent),
      device_(device)
{
    connect(device, &QIODevice::readyRead,
            this, &AbstractSocket::processIncomingData);
}

void AbstractSocket::sendMessage(const Message &message)
{
    QByteArray message_data = MsgPack::pack(message.toVariantList());
    QDataStream stream(device_);
    stream.writeBytes(message_data.constData(),
                      static_cast<uint>(message_data.size()));
}

void AbstractSocket::processIncomingData()
{
    buffer_.append(device_->readAll());

    // first 4 bytes constitute message length in big endian
    quint32 message_len = 0;
    while (static_cast<size_t>(buffer_.size()) <
           sizeof(message_len)) {

        QDataStream stream(&buffer_, QIODevice::ReadOnly);
        stream >> message_len;
        if (static_cast<size_t>(buffer_.size()) <
                message_len + sizeof(message_len)) break;

        // unpack message
        QByteArray message_data = buffer_.mid(sizeof(message_len),
                                              static_cast<int>(message_len));
        QVariantList message_content = MsgPack::unpack(message_data).toList();
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
            Response response(message_content);
            processResponse(response);
            break;
        }

        default:
            break;
        }

        buffer_.remove(0, static_cast<int>(sizeof(message_len) + message_len));
    }
}
