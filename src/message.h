#ifndef QMSGPACKRPC_MESSAGE_H
#define QMSGPACKRPC_MESSAGE_H

#include <QByteArray>

namespace MsgPackRpc
{

const quint8 kRequest = 0;
const quint8 kResponse = 1;
const quint8 kNotification = 2;

class Message
{
public:
    Message() {}
    virtual ~Message() {}
    virtual QByteArray pack() const = 0;
    virtual void unpack(const QByteArray &msg) = 0;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_MESSAGE_H
