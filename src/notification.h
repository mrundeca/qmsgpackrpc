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
    Notification() : Message(kNotification) {}
    Notification(const QVariantList &content);
    Notification(const QString &method, const QVariantList &params);

    const QString &method() const { return method_; }
    const QVariantList &params() const { return params_; }

    QByteArray pack() const override;
    void unpack(const QByteArray &msg) override;

private:
    QString method_;
    QVariantList params_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_NOTIFICATION_H
