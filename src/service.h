#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include "message.h"

namespace MsgPackRpc {

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);
    virtual Response dispatch(const Request &request) = 0;
    virtual void dispatch(const Notification &) {}

signals:

public slots:
};

} // namespace MsgPackRpc

#endif // SERVICE_H
