#ifndef PENDINGCALL_H
#define PENDINGCALL_H

#include <QObject>
#include "message.h"
#include "request.h"
#include "response.h"

namespace MsgPackRpc {

class PendingCall : public QObject
{
    Q_OBJECT
public:
    explicit PendingCall(QObject *parent = nullptr);

    const Message &request() const { return request_; }
    const Message &response() const { return response_; }

    bool waitForFinished(int msecs = 30000);

signals:
    void finished();

private:
    Request request_;
    Response response_;
};

} // namespace MsgPackRpc

#endif // PENDINGCALL_H
