#ifndef QMSGPACKRPC_RESPONSE_H
#define QMSGPACKRPC_RESPONSE_H

#include "message.h"

#include <QString>

namespace MsgPackRpc
{

class Response : public Message
{
public:
    Response();
    Response(const QVariant &error, const QVariant &result, quint32 msgid = 0);
    Response(const QVariantList &content);

    quint32 msgid() const { return msgid_; }
    QVariant result() const { return result_; }

    QVariantList toVariantList() const override;

private:
    quint32 msgid_;
    QVariant error_;
    QVariant result_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_RESPONSE_H
