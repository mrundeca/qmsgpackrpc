#ifndef ABSTRACTSOCKET_H
#define ABSTRACTSOCKET_H

#include <QByteArray>
#include <QIODevice>
#include <QObject>
#include <QSharedPointer>
#include "message.h"

namespace MsgPackRpc {

class AbstractSocket : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSocket(QIODevice *device, QObject *parent = nullptr);
    virtual ~AbstractSocket() {}

signals:
    void disconnected();

protected:
    virtual void sendMessage(const Message &message);
    virtual void processMessage(const QByteArray &message) = 0;

private slots:
    virtual void processIncomingData();

private:
    QIODevice *device_;
    QByteArray buffer_;
};

} // namespace MsgPackRpc

#endif // ABSTRACTSOCKET_H
