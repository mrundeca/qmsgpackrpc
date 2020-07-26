#ifndef ABSTRACTSOCKET_H
#define ABSTRACTSOCKET_H

#include <QByteArray>
#include <QIODevice>
#include <QObject>
#include <QSharedPointer>
#include "message.h"
#include "notification.h"
#include "request.h"

namespace MsgPackRpc {

class AbstractSocket : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSocket(QIODevice *device, QObject *parent = nullptr);

protected:
    virtual void sendMessage(const Message &message);
    virtual void processRequest(const Request &request);
    virtual void processNotification(const Notification &notification);

private slots:
    virtual void processIncomingData();

private:
    QIODevice *device_;
    QByteArray buffer_;
};

} // namespace MsgPackRpc

#endif // ABSTRACTSOCKET_H
