#ifndef QMSGPACKRPC_RESPONSE_H
#define QMSGPACKRPC_RESPONSE_H

#include "message.h"

#include <QString>
#include <QVariantList>

namespace MsgPackRpc
{

class Response : public Message
{
public:
    Response();
    Response(const QVariant &error, const QVariant &result, quint32 msgid = 0);

    QByteArray pack() const override;
    void unpack(const QByteArray &msg) override;

private:
    const quint8 type_ = kResponse;
    quint32 msgid_;
    QVariant error_;
    QVariant result_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_RESPONSE_H
