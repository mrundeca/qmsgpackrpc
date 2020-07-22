#ifndef QMSGPACKRPC_REQUEST_H
#define QMSGPACKRPC_REQUEST_H

#include "message.h"

#include <QString>
#include <QVariantList>

namespace MsgPackRpc
{

class Request : public Message
{
public:
    Request();
    Request(const QString &method, const QVariantList &params, quint32 msgid = 0);

    QByteArray pack() const override;
    void unpack(const QByteArray &msg) override;

private:
    const quint8 type_ = kRequest;
    quint32 msgid_;
    QString method_;
    QVariantList params_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_REQUEST_H
