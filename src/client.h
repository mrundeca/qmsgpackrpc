#ifndef CLIENT_H
#define CLIENT_H

#include <QIODevice>
#include <QObject>
#include <QString>
#include <QVariantList>
#include "abstractsocket.h"
#include "response.h"
#include "pendingcall.h"

namespace MsgPackRpc {

class Client : public AbstractSocket
{
    Q_OBJECT
public:
    Client(QIODevice *device, QObject *parent = nullptr);
    Response call(const QString &method, const QVariantList &params);
    PendingCall *asyncCall(const QString &method, const QVariantList &params);
    void notify(const QString &method, const QVariantList &params);

private:
    QIODevice *device_;
};

} // namespace MsgPackRpc

#endif // CLIENT_H
