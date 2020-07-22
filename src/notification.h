#ifndef QMSGPACKRPC_NOTIFICATION_H
#define QMSGPACKRPC_NOTIFICATION_H

#include "message.h"

#include <QString>
#include <QVariantList>

namespace MsgPackRpc
{

class Notification : public Message
{
public:
    Notification() {}
    Notification(const QString &method, const QVariantList &params);

    QByteArray pack() const override;
    void unpack(const QByteArray &msg) override;

private:
    const quint8 type_ = kNotification;
    QString method_;
    QVariantList params_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_NOTIFICATION_H
