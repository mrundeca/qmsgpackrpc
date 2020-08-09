#ifndef PENDINGCALL_H
#define PENDINGCALL_H

#include <QObject>
#include "message.h"

namespace MsgPackRpc {

class PendingCall : public QObject
{
    Q_OBJECT
public:
    explicit PendingCall(const Request &request, QObject *parent = nullptr);

    const Request &request() const { return request_; }
    const Response &response() const { return response_; }
    void finishRequest(const Response &response);
    bool waitForFinished(int msecs = 30000);

signals:
    void finished();

private:
    Request request_;
    Response response_;
};

} // namespace MsgPackRpc

#endif // PENDINGCALL_H
