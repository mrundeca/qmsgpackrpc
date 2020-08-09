#ifndef SERVICESOCKET_H
#define SERVICESOCKET_H

#include "abstractsocket.h"
#include "service.h"

namespace MsgPackRpc {

class ServiceSocket : public AbstractSocket
{
    Q_OBJECT
public:
    ServiceSocket(Service *service, QIODevice *device, QObject *parent = nullptr);

protected:
    void processMessage(const QByteArray &message) override;
    virtual void processRequest(const Request &request);
    virtual void processNotification(const Notification &notification);

private:
    Service *service_;
};

} // namespace MsgPackRpc

#endif // SERVICESOCKET_H
