#ifndef CLIENT_H
#define CLIENT_H

#include <QIODevice>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVector>
#include "abstractsocket.h"
#include "pendingcall.h"

namespace MsgPackRpc {

class Client : public AbstractSocket
{
    Q_OBJECT
public:
    Client(QIODevice *device, QObject *parent = nullptr);
    ~Client() override;
    PendingCall *call(const QString &method, const QVariantList &params);
    void notify(const QString &method, const QVariantList &params);
    virtual void dispatch(const Notification &notification);
    int timeout() const { return timeout_; }
    void setTimeout(int timeout) { timeout_ = timeout; }

protected:
    virtual void processMessage(const QByteArray &message) override;
    virtual void processNotification(const Notification &notification);
    virtual void processResponse(const Response &response);

private:
    virtual void dispatch(const Response &response);

private:
    QIODevice *device_;
    int timeout_;
    quint32 msgid_;
    QVector<PendingCall *> pending_calls_;
};

} // namespace MsgPackRpc

#endif // CLIENT_H
