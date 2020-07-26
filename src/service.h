#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include "notification.h"
#include "request.h"

namespace MsgPackRpc {

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);
    void dispatch(const Request &request);
    void dispatch(const Notification &notification);

signals:

public slots:
};

} // namespace MsgPackRpc

#endif // SERVICE_H
