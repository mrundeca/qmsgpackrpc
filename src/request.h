#ifndef QMSGPACKRPC_REQUEST_H
#define QMSGPACKRPC_REQUEST_H

#include "message.h"

#include <QString>

namespace MsgPackRpc
{

class Request : public Message
{
public:
    Request() : Message(kRequest), msgid_(0) {}
    Request(const QVariantList &content);
    Request(const QString &method, const QVariantList &params, quint32 msgid = 0);

    quint32 msgid() const { return msgid_; }
    const QString &method() const { return method_; }
    const QVariantList &params() const { return params_; }

    QVariantList toVariantList() const override;

private:
    quint32 msgid_;
    QString method_;
    QVariantList params_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_REQUEST_H
