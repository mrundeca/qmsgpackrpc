#ifndef ABSTRACTSOCKET_H
#define ABSTRACTSOCKET_H

#include <QByteArray>
#include <QIODevice>
#include <QObject>
#include <QSharedPointer>
#include "message.h"
#include "notification.h"
#include "response.h"
#include "request.h"

namespace MsgPackRpc {

class AbstractSocket : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSocket(QIODevice *device, QObject *parent = nullptr);

signals:
    void disconnected();

protected:
    virtual void sendMessage(const Message &message);
    virtual void processRequest(const Request &request) = 0;
    virtual void processNotification(const Notification &notification) = 0;
    virtual void processResponse(const Response &response) = 0;

private slots:
    virtual void processIncomingData();

private:
    QIODevice *device_;
    QByteArray buffer_;
};

} // namespace MsgPackRpc

#endif // ABSTRACTSOCKET_H
