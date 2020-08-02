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
    void processRequest(const Request &request) override;
    void processNotification(const Notification &notification) override;
    void processResponse(const Response &response) override;

private:
    Service *service_;
};

} // namespace MsgPackRpc

#endif // SERVICESOCKET_H
