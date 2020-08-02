#ifndef QMSGPACKRPC_MESSAGE_H
#define QMSGPACKRPC_MESSAGE_H

#include <QByteArray>
#include <QVariantList>

namespace MsgPackRpc
{

const quint8 kRequest = 0;
const quint8 kResponse = 1;
const quint8 kNotification = 2;

class Message
{
public:
    Message() : type_(kRequest) {}
    Message(quint8 type) : type_(type) {}
    virtual ~Message() {}
    virtual QVariantList toVariantList() const = 0;

protected:
    quint8 type_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_MESSAGE_H
